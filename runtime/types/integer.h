//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_INTEGER_H
#define PYTHONVM_RUNTIME_TYPES_INTEGER_H

#include "object.h"

class Integer : public Object {
public:
    Integer(int value) : value_(value) {}

    int value() { return value_; };

private:
    int value_;
};

#endif // PYTHONVM_RUNTIME_TYPES_INTEGER_H
