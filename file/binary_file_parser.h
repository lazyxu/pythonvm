//
// Created by xuliang on 2021/9/4.
//

#ifndef PYTHONVM_FILE_BINARY_FILE_PARSER_H
#define PYTHONVM_FILE_BINARY_FILE_PARSER_H

#include "../utils/buffered_input_stream.h"
#include "code_object.h"

class BinaryFileParser {
public:
    explicit BinaryFileParser(BufferedInputStream *stream);
    CodeObject *parse();

private:
    BufferedInputStream *file_stream_;
    ArrayList<String *> string_table_;
    CodeObject *get_code_object();
    String *get_byte_codes();
    String *get_string();
    String *get_no_table();
    String *get_name();
    ArrayList<Object *> *try_get_tuple();
    ArrayList<Object *> *get_tuple();
};

#endif // PYTHONVM_FILE_BINARY_FILE_PARSER_H
