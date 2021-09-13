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

    ASSERT(oo != nullptr && oo->klass() == this);

    for (int i = 0; i < oo->length(); i++) {
        std::cout.put(oo->value()[i]);
    }
}

Object *StringKlass::eq(Object *x, Object *y) {
    auto *xx = dynamic_cast<String *>(x);
    auto *yy = dynamic_cast<String *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return strcmp(xx->value(), yy->value()) == 0 ? Universe::True
                                                 : Universe::False;
}

Object *StringKlass::len(Object *o) {
    auto *oo = dynamic_cast<String *>(o);

    ASSERT(oo != nullptr && oo->klass() == this);

    return new Integer(oo->length());
}

String::String(const char *value, uint32_t length) {
    length_ = length;
    value_ = new char[length_];
    memcpy(value_, value, length);
    set_klass(StringKlass::get_instance());
}

std::vector<String *> *String::cache_ = new std::vector<String *>();

String *String::get_instance(const char *value, uint32_t length) {
    for (const auto &item : *cache_) {
        if (memcmp(item->value(), value, std::max(item->length(), length)) ==
            0) {
            return item;
        }
    }
    auto value_ = new char[length];
    memcpy(value_, value, length);
    auto str = new String(value_, length);
    cache_->emplace_back(str);
    return str;
}

String *String::get_instance(const char *value) {
    return get_instance(value, strlen(value));
}

bool operator==(const String &lhs, const String &rhs) {
    if (rhs.klass() != StringKlass::get_instance()) {
        return false;
    }
    return StringKlass::get_instance()->eq(const_cast<String *>(&lhs),
                                           const_cast<String *>(&rhs));
}
