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

    Map<Object *, Object *> *globals() { return globals_; }
    void set_globals(Map<Object *, Object *> *globals) { globals_ = globals; }

    CodeObject *code_object_;
    Map<Object *, Object *> *globals_;
};

#endif // PYTHONVM_RUNTIME_TYPES_FUNCTION_H
