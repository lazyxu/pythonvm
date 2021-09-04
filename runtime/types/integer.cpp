//
// Created by xuliang on 2021/9/2.
//

#include "integer.h"
#include "../universe.h"

#include <iostream>

void Integer::print() { std::cout << value_; }

Object *Integer::add(Object *o) {
    return new Integer(value_ + dynamic_cast<Integer *>(o)->value_);
}

Object *Integer::less(Object *o) {
    return value_ < dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                       : Universe::False;
}

Object *Integer::le(Object *o) {
    return value_ <= dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                        : Universe::False;
}

Object *Integer::eq(Object *o) {
    return value_ == dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                        : Universe::False;
}

Object *Integer::ne(Object *o) {
    return value_ != dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                        : Universe::False;
}

Object *Integer::greater(Object *o) {
    return value_ > dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                       : Universe::False;
}

Object *Integer::ge(Object *o) {
    return value_ >= dynamic_cast<Integer *>(o)->value_ ? Universe::True
                                                        : Universe::False;
}
