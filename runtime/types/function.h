//
// Created by xuliang on 2021/9/7.
//

#ifndef PYTHONVM_RUNTIME_TYPES_FUNCTION_H
#define PYTHONVM_RUNTIME_TYPES_FUNCTION_H

#include "../../file/code_object.h"
#include "klass.h"

class FunctionKlass : public Klass {
public:
    static FunctionKlass *get_instance();
    void print(Object *o) override;

private:
    FunctionKlass();
    static FunctionKlass *klass;
};

class FunctionObject : public Object {
public:
    explicit FunctionObject(Object *o);

    String *func_name() { return code_object_->co_name_; };

private:
    CodeObject *code_object_;
};

#endif // PYTHONVM_RUNTIME_TYPES_FUNCTION_H
