//
// Created by xuliang on 2021/9/7.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_FRAME_OBJECT_H
#define PYTHONVM_RUNTIME_INTERPRETER_FRAME_OBJECT_H

#include "../../file/code_object.h"
#include "../types/function.h"
#include "block.h"

class FrameObject {
public:
    explicit FrameObject(CodeObject *codes);
    explicit FrameObject(FunctionObject *func, ArrayList<Object *> *args);
    ArrayList<Object *> *args() const { return args_; }
    ArrayList<Object *> *stack() const { return stack_; }
    ArrayList<Object *> *consts() const { return consts_; }
    ArrayList<Object *> *names() const { return names_; }
    Map<Object *, Object *> *locals() const { return locals_; }
    ArrayList<Block *> *loop_stack() const { return loop_stack_; }
    void set_pc(int pc) { pc_ = pc; }
    int get_pc() const { return pc_; }
    unsigned char get_op_code() { return codes_->bytecodes_->value()[pc_++]; }
    int get_op_arg() {
        int b1 = (codes_->bytecodes_->value()[pc_++] & 0xFF);
        return ((codes_->bytecodes_->value()[pc_++] & 0xFF) << 8) | b1;
    }
    bool has_more_codes() { return pc_ < codes_->bytecodes_->length(); }

    void set_prev(FrameObject *prev) { prev_ = prev; }
    FrameObject *prev() { return prev_; };
    Map<Object *, Object *> *globals() { return globals_; }

private:
    FrameObject *prev_ = nullptr;
    ArrayList<Object *> *args_;
    ArrayList<Object *> *stack_;
    ArrayList<Object *> *consts_;
    ArrayList<Object *> *names_;
    Map<Object *, Object *> *locals_;
    Map<Object *, Object *> *globals_;
    ArrayList<Block *> *loop_stack_;
    CodeObject *codes_;
    int pc_;
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_FRAME_OBJECT_H
