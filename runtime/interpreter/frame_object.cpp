//
// Created by xuliang on 2021/9/7.
//

#include "frame_object.h"

FrameObject::FrameObject(CodeObject *codes) {
    consts_ = codes->consts_;
    names_ = codes->names_;

    stack_ = new ArrayList<Object *>();
    locals_ = new Map<Object *, Object *>();
    loop_stack_ = new ArrayList<Block *>();
    codes_ = codes;
    pc_ = 0;
}
