//
// Created by xuliang on 2021/9/4.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
#define PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H

#include "../../file/code_object.h"

class Interpreter {
public:
    void run(CodeObject *codes);

private:
    ArrayList<Object *> *stack_;
    ArrayList<Object *> *consts_;
    inline void push(Object *o);
    inline Object *pop();
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_INTERPRETER_H
