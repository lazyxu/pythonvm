//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_STRING_H
#define PYTHONVM_RUNTIME_TYPES_STRING_H

#include "integer.h"
#include "object.h"
#include <cstdint>

class StringKlass : public Klass {
public:
    static StringKlass *get_instance();
    void print(Object *o) override;

    Object *eq(Object *x, Object *y) override;
    Object *len(Object *o) override;

private:
    StringKlass();
    static StringKlass *klass;
};

class String : public Object {
public:
    explicit String(const char *value);

    String(const char *value, int length);

    const char *value() { return value_; };

    const uint32_t length() { return length_; };

private:
    char *value_;
    uint32_t length_;
};

#endif // PYTHONVM_RUNTIME_TYPES_STRING_H
