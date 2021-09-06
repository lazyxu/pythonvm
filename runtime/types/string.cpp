//
// Created by xuliang on 2021/9/2.
//

#include "string.h"
#include "../universe.h"

#include <cstring>
#include <iostream>

StringKlass::StringKlass() {}

StringKlass *StringKlass::klass = nullptr;

StringKlass *StringKlass::get_instance() {
    if (klass == nullptr) {
        klass = new StringKlass();
    }
    return klass;
}

void StringKlass::print(Object *o) {
    auto *oo = dynamic_cast<String *>(o);

    assert(oo != nullptr && oo->klass() == this);

    for (int i = 0; i < oo->length(); i++) {
        std::cout.put(oo->value()[i]);
    }
}

Object *StringKlass::eq(Object *x, Object *y) {
    auto *xx = dynamic_cast<String *>(x);
    auto *yy = dynamic_cast<String *>(y);

    assert(xx != nullptr && (xx->klass() == (Klass *)this));
    assert(yy != nullptr && (yy->klass() == (Klass *)this));

    return strcmp(xx->value(), yy->value()) == 0 ? Universe::True
                                                 : Universe::False;
}

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
