//
// Created by xuliang on 2021/9/4.
//

#include "interpreter.h"

#include "../../utils/logger.h"
#include "bytecode.h"

void Interpreter::run(CodeObject *codes) {
    uint32_t pc = 0;
    auto code_length = codes->bytecodes_->length();
    stack_ = new ArrayList<Object *>(codes->stack_size_);
    consts_ = codes->consts_;

    while (pc < code_length) {
        auto op_code = codes->bytecodes_->value()[pc++];
        bool has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;
        if (has_argument) {
            int b1 = (codes->bytecodes_->value()[pc++] & 0xFF);
            op_arg = ((codes->bytecodes_->value()[pc++] & 0xFF) << 8) | b1;
        }

        Object *v, *w;

        switch (op_code) {
        case ByteCode::LOAD_CONST:
            stack_->push_back(consts_->at(op_arg));
            break;
        case ByteCode::PRINT_ITEM:
            v = stack_->back();
            stack_->pop_back();
            v->print();
            break;
        case ByteCode::PRINT_NEWLINE:
            std::cout << std::endl;
            break;
        case ByteCode::BINARY_ADD:
            v = stack_->back();
            stack_->pop_back();
            w = stack_->back();
            stack_->pop_back();
            stack_->push_back(w->add(v));
            break;
        case ByteCode::RETURN_VALUE:
            stack_->pop_back();
            break;
        default:
            LOG(FATAL) << "Error: Unrecognized byte code " << op_code;
        }
    }
}
