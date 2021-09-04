//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_STRING_H
#define PYTHONVM_RUNTIME_TYPES_STRING_H

#include "object.h"
#include <cstdint>

class String : public Object {
public:
    explicit String(const char *value);

    String(const char *value, int length);

    const char *value() { return value_; };

private:
    char *value_;
    uint32_t length_;
};

#endif // PYTHONVM_RUNTIME_TYPES_STRING_H
