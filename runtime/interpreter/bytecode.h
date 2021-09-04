//
// Created by xuliang on 2021/9/4.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_BYTECODE_H
#define PYTHONVM_RUNTIME_INTERPRETER_BYTECODE_H

class ByteCode {
public:
    static const unsigned char BINARY_ADD = 23;
    static const unsigned char PRINT_ITEM = 71;
    static const unsigned char PRINT_NEWLINE = 72;
    static const unsigned char RETURN_VALUE = 83;
    static const unsigned char HAVE_ARGUMENT = 90;
    static const unsigned char LOAD_CONST = 100;
    static const unsigned char COMPARE = 107;
    static const unsigned char JUMP_FORWARD = 110;
    static const unsigned char POP_JUMP_IF_FALSE = 114;
    enum Compare {
        LESS = 0,
        LESS_EQUAL,
        EQUAL,
        NOT_EQUAL,
        GREATER,
        GREATER_EQUAL,
    };
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_BYTECODE_H
