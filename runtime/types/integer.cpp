//
// Created by xuliang on 2021/9/2.
//

#include "integer.h"

#include <iostream>

void Integer::print() { std::cout << value_; }

Object *Integer::add(Object *o) {
    return new Integer(value_ + dynamic_cast<Integer *>(o)->value_);
}
