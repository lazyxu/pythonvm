//
// Created by xuliang on 2021/9/4.
//

#include "interpreter.h"

#include "../../utils/logger.h"
#include "../types/integer.h"
#include "../universe.h"
#include "bytecode.h"

void Interpreter::push(Object *o) { stack_->push_back(o); }

Object *Interpreter::pop() {
    auto v = stack_->back();
    stack_->pop_back();
    return v;
}

void Interpreter::run(CodeObject *codes) {
    uint32_t pc = 0;
    auto code_length = codes->bytecodes_->length();
    stack_ = new ArrayList<Object *>();
    consts_ = codes->consts_;
    names_ = codes->names_;

    while (pc < code_length) {
        auto op_code = codes->bytecodes_->value()[pc++];
        bool has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;
        if (has_argument) {
            int b1 = (codes->bytecodes_->value()[pc++] & 0xFF);
            op_arg = ((codes->bytecodes_->value()[pc++] & 0xFF) << 8) | b1;
        }

        Object *v, *w;
        Block *b;

        switch (op_code) {
        case ByteCode::LOAD_CONST:
            push(consts_->at(op_arg));
            break;
        case ByteCode::PRINT_ITEM:
            v = pop();
            v->print();
            break;
        case ByteCode::PRINT_NEWLINE:
            std::cout << std::endl;
            break;
        case ByteCode::BINARY_ADD:
            w = pop();
            v = pop();
            push(v->add(w));
            break;
        case ByteCode::RETURN_VALUE:
            pop();
            break;
        case ByteCode::COMPARE:
            w = pop();
            v = pop();
            switch (op_arg) {
            case ByteCode::LESS:
                push(v->less(w));
                break;
            case ByteCode::LESS_EQUAL:
                push(v->le(w));
                break;
            case ByteCode::EQUAL:
                push(v->eq(w));
                break;
            case ByteCode::NOT_EQUAL:
                push(v->ne(w));
                break;
            case ByteCode::GREATER:
                push(v->greater(w));
                break;
            case ByteCode::GREATER_EQUAL:
                push(v->ge(w));
                break;
            default:
                LOG(FATAL) << "Error: Unrecognized compare op " << int(op_arg);
            }
            break;
        case ByteCode::POP_JUMP_IF_FALSE:
            v = pop();
            if (v == Universe::False) {
                pc = op_arg;
            }
            break;
        case ByteCode::JUMP_ABSOLUTE:
            pc = op_arg;
            break;
        case ByteCode::JUMP_FORWARD:
            pc += op_arg;
            break;
        case ByteCode::POP_BLOCK:
            b = loop_stack_.back();
            loop_stack_.pop_back();
            while (stack_->size() > b->level_) {
                pop();
            }
            break;
        case ByteCode::BREAK_LOOP:
            b = loop_stack_.back();
            loop_stack_.pop_back();
            while (stack_->size() > b->level_) {
                pop();
            }
            pc = b->target_;
            break;
        case ByteCode::SETUP_LOOP:
            loop_stack_.push_back(
                new Block(op_code, pc + op_arg, stack_->size()));
            break;
        case ByteCode::STORE_NAME:
            v = names_->at(op_arg);
            w = pop();
            locals_[v] = w;
            break;
        case ByteCode::LOAD_NAME:
            v = names_->at(op_arg);
            w = locals_.at(v);
            push(w);
            break;
        default:
            LOG(FATAL) << "Error: Unrecognized byte code " << int(op_code);
        }
    }
}
