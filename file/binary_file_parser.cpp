//
// Created by xuliang on 2021/9/4.
//

#include "binary_file_parser.h"
#include "../runtime/types/integer.h"
#include "../runtime/universe.h"
#include "../utils/logger.h"
#include <iomanip>
BinaryFileParser::BinaryFileParser(BufferedInputStream *stream) {
    file_stream_ = stream;
}

CodeObject *BinaryFileParser::parse() {
    auto magic_number = file_stream_->read_int();
    LOG(DEBUG) << "magic number is " << std::hex << magic_number;
    auto mod_date = file_stream_->read_int();
    std::time_t t(mod_date);
    LOG(DEBUG) << "mod date is " << std::put_time(std::localtime(&t), "%F %T");

    auto object_type = file_stream_->read();
    if (object_type == 'c') {
        CodeObject *result = get_code_object();
        LOG(DEBUG) << "parse " << result->file_path_->value() << " ok!";
        return result;
    }

    return nullptr;
}

CodeObject *BinaryFileParser::get_code_object() {
    auto arg_count = file_stream_->read_int();
    auto nlocals = file_stream_->read_int();
    auto stack_size = file_stream_->read_int();
    auto flags = file_stream_->read_int();

    String *byte_codes = get_byte_codes();
    ArrayList<Object *> *consts = try_get_tuple();
    ArrayList<Object *> *names = try_get_tuple();
    ArrayList<Object *> *var_names = try_get_tuple();
    ArrayList<Object *> *free_vars = try_get_tuple();
    ArrayList<Object *> *cell_vars = try_get_tuple();
    String *file_name = get_name();
    String *module_name = get_name();
    auto begin_line_no = file_stream_->read_int();
    String *lnotab = get_no_table();
    String *file_path = String::get_instance(file_stream_->get_file_path());

    return new CodeObject(arg_count, nlocals, stack_size, flags, byte_codes,
                          consts, names, var_names, free_vars, cell_vars,
                          file_name, module_name, begin_line_no, lnotab,
                          file_path);
}

String *BinaryFileParser::get_byte_codes() {
    ASSERT(file_stream_->read() == 's');

    return get_string();
}

String *BinaryFileParser::get_string() {
    auto length = file_stream_->read_int();
    auto *str_val = new char[length];
    for (int i = 0; i < length; ++i) {
        str_val[i] = file_stream_->read();
    }

    auto *s = String::get_instance(str_val, length);
    delete[] str_val;
    return s;
}

String *BinaryFileParser::get_no_table() {
    char ch = file_stream_->read();

    if (ch != 's' && ch != 't') {
        file_stream_->unread();
        return nullptr;
    }

    return get_string();
}

String *BinaryFileParser::get_name() {
    char ch = file_stream_->read();

    if (ch == 's') {
        return get_string();
    } else if (ch == 't') {
        String *str = get_string();
        string_table_.push_back(str);
        return str;
    } else if (ch == 'R') {
        return string_table_.at(file_stream_->read_int());
    }

    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::try_get_tuple() {
    if (file_stream_->read() == '(') {
        return get_tuple();
    }

    file_stream_->unread();
    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::get_tuple() {
    auto length = file_stream_->read_int();
    String *str;
    auto list = new ArrayList<Object *>();
    for (int i = 0; i < length; ++i) {
        auto obj_type = file_stream_->read();
        switch (obj_type) {
        case 'c':
            list->push_back(get_code_object());
            break;
        case 'i':
            list->push_back(new Integer(file_stream_->read_int()));
            break;
        case 'N':
            list->push_back(Universe::None);
            break;
        case 't':
            str = get_string();
            list->push_back(str);
            string_table_.push_back(str);
            break;
        case 's':
            list->push_back(get_string());
            break;
        case 'R':
            list->push_back(string_table_.at(file_stream_->read_int()));
            break;
        default:
            LOG(FATAL) << "parser, unrecognized type " << obj_type;
        }
    }
    return list;
}
