//
// Created by xuliang on 2021/9/2.
//

#include "object.h"

#include "../../utils/logger.h"
#include <iostream>

void Object::print() { std::cout << "Object" << std::endl; }

Object *Object::add(Object *o) { LOG(FATAL) << "Unimplemented Operation!"; }
