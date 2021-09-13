//
// Created by xuliang on 2021/9/7.
//

#include "frame_object.h"

FrameObject::FrameObject(CodeObject *codes) {
    consts_ = codes->consts_;
    names_ = codes->names_;

    stack_ = new ArrayList<Object *>();
    locals_ = new Map<Object *, Object *>();
    globals_ = locals_;
    loop_stack_ = new ArrayList<Block *>();
    codes_ = codes;
    pc_ = 0;
}

FrameObject::FrameObject(FunctionObject *func, ArrayList<Object *> *args)
    : FrameObject(func->code_object_) {
    if (args) {
        args_ = new ArrayList<Object *>(*args);
    }
}
