//
// Created by xuliang on 2021/9/2.
//

#include "object.h"

#include "../../utils/logger.h"
#include <iostream>

void Object::print() { std::cout << "Object" << std::endl; }

Object *Object::add(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::less(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::le(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::eq(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::ne(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::greater(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}

Object *Object::ge(Object *o) {
    LOG(FATAL) << "Unimplemented Operation!" << __func__;
    return nullptr;
}
