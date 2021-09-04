//
// Created by xuliang on 2021/9/4.
//

#include "binary_file_parser.h"
#include <iomanip>
BinaryFileParser::BinaryFileParser(BufferedInputStream *stream) {
    file_stream_ = stream;
}

CodeObject *BinaryFileParser::parse() {
    int magic_number = file_stream_->read_int();
    std::cout << "magic number is " << std::hex << magic_number << std::endl;
    int mod_date = file_stream_->read_int();
    std::time_t t(mod_date);
    std::cout << "mod date is " << std::put_time(std::localtime(&t), "%F %T")
              << std::endl;

    char object_type = file_stream_->read();
    if (object_type == 'c') {
        CodeObject *result = get_code_object();
        std::cout << "parse ok!" << std::endl;
        return result;
    }

    return nullptr;
}

CodeObject *BinaryFileParser::get_code_object() { return nullptr; }
