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

class NativeFunctionKlass : public Klass {
public:
    static NativeFunctionKlass *get_instance();

private:
    NativeFunctionKlass();
    static NativeFunctionKlass *klass;
};

typedef Object *(*NativeFuncPointer)(ArrayList<Object *> *);

class FunctionObject : public Object {
public:
    explicit FunctionObject(Object *o);
    explicit FunctionObject(NativeFuncPointer nfp);

    Object *call(ArrayList<Object *> *args) { return (*native_func_)(args); }

    String *func_name() { return code_object_->co_name_; };

    Map<Object *, Object *> *globals() { return globals_; }
    void set_globals(Map<Object *, Object *> *globals) { globals_ = globals; }

    ArrayList<Object *> *defaults() { return defaults_; }
    void set_defaults(ArrayList<Object *> *defaults) {
        if (defaults) {
            defaults_ = new ArrayList<Object *>(*defaults);
        }
    }

    CodeObject *code_object_ = nullptr;
    Map<Object *, Object *> *globals_ = nullptr;
    ArrayList<Object *> *defaults_ = nullptr;
    NativeFuncPointer native_func_ = nullptr;
};

Object *len(ArrayList<Object *> *args);

#endif // PYTHONVM_RUNTIME_TYPES_FUNCTION_H
