//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_INTEGER_H
#define PYTHONVM_RUNTIME_TYPES_INTEGER_H

#include "object.h"

class IntegerKlass : public Klass {
public:
    static IntegerKlass *get_instance();
    void print(Object *o) override;

    Object *less(Object *x, Object *y) override;
    Object *le(Object *x, Object *y) override;
    Object *eq(Object *x, Object *y) override;
    Object *ne(Object *x, Object *y) override;
    Object *greater(Object *x, Object *y) override;
    Object *ge(Object *x, Object *y) override;

    Object *add(Object *x, Object *y) override;
    Object *sub(Object *x, Object *y) override;
    Object *mul(Object *x, Object *y) override;
    Object *div(Object *x, Object *y) override;
    Object *mod(Object *x, Object *y) override;

private:
    IntegerKlass();
    static IntegerKlass *klass;
};

class Integer : public Object {
public:
    explicit Integer(int value) : value_(value) {
        set_klass(IntegerKlass::get_instance());
    }

    int value() const { return value_; };

private:
    int value_;
};

#endif // PYTHONVM_RUNTIME_TYPES_INTEGER_H
