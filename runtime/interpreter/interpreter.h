//
// Created by xuliang on 2021/9/4.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
#define PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H

#include "../../file/code_object.h"
#include "block.h"
#include "frame_object.h"

class Interpreter {
public:
    Interpreter();
    void run(CodeObject *codes);

private:
    Map<Object *, Object *> *buildins_;
    FrameObject *frame_;
    inline void push(Object *o);
    inline Object *pop();
    void build_frame(Object *v);
    void eval_frame();
    void destroy_frame();
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
