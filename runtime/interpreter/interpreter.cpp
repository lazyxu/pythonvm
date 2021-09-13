//
// Created by xuliang on 2021/9/4.
//

#include "interpreter.h"

#include "../../utils/logger.h"
#include "../types/function.h"
#include "../types/integer.h"
#include "../universe.h"
#include "bytecode.h"

Interpreter::Interpreter() {
    buildins_ = new Map<Object *, Object *>;
    buildins_->insert({new String("True"), Universe::True});
    buildins_->insert({new String("False"), Universe::False});
    buildins_->insert({new String("None"), Universe::None});
}

void Interpreter::push(Object *o) { frame_->stack()->push_back(o); }

Object *Interpreter::pop() {
    auto v = frame_->stack()->back();
    frame_->stack()->pop_back();
    return v;
}

void Interpreter::run(CodeObject *codes) {
    frame_ = new FrameObject(codes);
    eval_frame();
    destroy_frame();
}

void Interpreter::eval_frame() {
    while (frame_->has_more_codes()) {
        auto op_code = frame_->get_op_code();
        bool has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;
        if (has_argument) {
            op_arg = frame_->get_op_arg();
        }

        Object *v, *w;
        Block *b;
        FunctionObject *fo;

        switch (op_code) {
        case ByteCode::POP_TOP:
            pop();
            break;
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
            v = pop();
            if (frame_->prev() == nullptr) {
                return;
            }
            destroy_frame();
            push(v);
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
            case ByteCode::IS:
                v == w ? push(Universe::True) : push(Universe::False);
                break;
            case ByteCode::IS_NOT:
                v == w ? push(Universe::False) : push(Universe::True);
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
        case ByteCode::STORE_GLOBAL:
            v = frame_->names()->at(op_arg);
            w = pop();
            (*frame_->globals())[v] = w;
            break;
        case ByteCode::LOAD_NAME:
            v = frame_->names()->at(op_arg);
            if (frame_->locals()->contains(v)) {
                w = frame_->locals()->at(v);
                if (w != Universe::None) {
                    push(w);
                    break;
                }
            }
            if (frame_->globals()->contains(v)) {
                w = frame_->globals()->at(v);
                if (w != Universe::None) {
                    push(w);
                    break;
                }
            }
            if (buildins_->contains(v)) {
                w = buildins_->at(v);
                if (w != Universe::None) {
                    push(w);
                    break;
                }
            }
            push(Universe::None);
            break;
        case ByteCode::LOAD_GLOBAL:
            v = frame_->names()->at(op_arg);
            if (frame_->globals()->contains(v)) {
                w = frame_->globals()->at(v);
                if (w != Universe::None) {
                    push(w);
                    break;
                }
            }
            push(Universe::None);
        case ByteCode::MAKE_FUNCTION:
            v = pop();
            fo = new FunctionObject(v);
            fo->set_globals(frame_->globals());
            push(fo);
            break;
        case ByteCode::CALL_FUNCTION:
            v = pop();
            build_frame(v);
            break;
        default:
            LOG(FATAL) << "Error: Unrecognized byte code " << int(op_code);
        }
    }
}

void Interpreter::build_frame(Object *v) {
    auto frame = new FrameObject(dynamic_cast<FunctionObject *>(v));
    frame->set_prev(frame_);
    frame_ = frame;
}

void Interpreter::destroy_frame() {
    auto *temp = frame_;
    frame_ = frame_->prev();
    delete temp;
}
