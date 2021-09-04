//
// Created by xuliang on 2021/9/5.
//

#include "universe.h"
Integer *Universe::True = nullptr;
Integer *Universe::False = nullptr;
Object *Universe::None = nullptr;

void Universe::genesis() {
    True = new Integer(1);
    False = new Integer(0);
    None = new Object();
}

void Universe::destroy() {}
