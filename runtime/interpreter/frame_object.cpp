//
// Created by xuliang on 2021/9/7.
//

#include "frame_object.h"
#include "../../utils/logger.h"

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
        args_ = new ArrayList<Object *>();
        args_->resize(codes_->arg_count_);
        auto default_cnt = func->defaults() ? func->defaults()->size() : 0;
        if (default_cnt + args->size() < codes_->arg_count_) {
            LOG(FATAL) << "Error: not enough args";
        }
        for (auto i = 0; i < args->size(); ++i) {
            args_->operator[](i) = args->at(i);
        }
        for (auto i = 0; i < default_cnt; ++i) {
            args_->operator[](codes_->arg_count_ - default_cnt + i) =
                func->defaults()->at(i);
        }
    }
}
