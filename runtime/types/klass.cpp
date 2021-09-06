//
// Created by xuliang on 2021/9/5.
//

#include "klass.h"

#include "../../utils/logger.h"
#include <iostream>

void Klass::print(Object *o) { std::cout << "Object" << std::endl; }

Object *Klass::less(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::le(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::eq(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::ne(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::greater(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::ge(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::add(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::sub(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::mul(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::div(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Klass::mod(Object *x, Object *y) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}
