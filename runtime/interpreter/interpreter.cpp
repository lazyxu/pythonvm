//
// Created by xuliang on 2021/9/4.
//

#include "interpreter.h"

#include "../../utils/logger.h"
#include "../types/integer.h"
#include "../universe.h"
#include "bytecode.h"

void Interpreter::push(Object *o) { frame_->stack()->push_back(o); }

Object *Interpreter::pop() {
    auto v = frame_->stack()->back();
    frame_->stack()->pop_back();
    return v;
}

void Interpreter::run(CodeObject *codes) {
    frame_ = new FrameObject(codes);

    while (frame_->has_more_codes()) {
        auto op_code = frame_->get_op_code();
        bool has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;
        if (has_argument) {
            op_arg = frame_->get_op_arg();
        }

        Object *v, *w;
        Block *b;

        switch (op_code) {
        case ByteCode::LOAD_CONST:
            push(frame_->consts()->at(op_arg));
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
                frame_->set_pc(op_arg);
            }
            break;
        case ByteCode::JUMP_ABSOLUTE:
            frame_->set_pc(op_arg);
            break;
        case ByteCode::JUMP_FORWARD:
            frame_->set_pc(frame_->get_pc() + op_arg);
            break;
        case ByteCode::POP_BLOCK:
            b = frame_->loop_stack()->back();
            frame_->loop_stack()->pop_back();
            while (frame_->stack()->size() > b->level_) {
                pop();
            }
            break;
        case ByteCode::BREAK_LOOP:
            b = frame_->loop_stack()->back();
            frame_->loop_stack()->pop_back();
            while (frame_->stack()->size() > b->level_) {
                pop();
            }
            frame_->set_pc(b->target_);
            break;
        case ByteCode::SETUP_LOOP:
            frame_->loop_stack()->push_back(new Block(
                op_code, frame_->get_pc() + op_arg, frame_->stack()->size()));
            break;
        case ByteCode::STORE_NAME:
            v = frame_->names()->at(op_arg);
            w = pop();
            (*frame_->locals())[v] = w;
            break;
        case ByteCode::LOAD_NAME:
            v = frame_->names()->at(op_arg);
            ASSERT(frame_->locals()->contains(v));
            w = frame_->locals()->at(v);
            push(w);
            break;
        default:
            LOG(FATAL) << "Error: Unrecognized byte code " << int(op_code);
        }
    }
}
