//
// Created by xuliang on 2021/9/2.
//

#include "string.h"

#include <cstring>

String::String(const char *value) {
    length_ = strlen(value);
    value_ = new char[length_];
    strcpy(value_, value);
}

String::String(const char *value, int length) {
    length_ = length;
    value_ = new char[length_];
    memcpy(value_, value, length_);
}
