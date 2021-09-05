//
// Created by xuliang on 2021/9/4.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
#define PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H

#include "../../file/code_object.h"
#include "block.h"

class Interpreter {
public:
    void run(CodeObject *codes);

private:
    ArrayList<Object *> *stack_;
    ArrayList<Object *> *consts_;
    ArrayList<Object *> *names_;
    Map<Object *, Object *> locals_;
    ArrayList<Block *> loop_stack_;
    inline void push(Object *o);
    inline Object *pop();
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
