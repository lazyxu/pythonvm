//
// Created by xuliang on 2021/9/5.
//

#ifndef PYTHONVM_RUNTIME_UNIVERSE_H
#define PYTHONVM_RUNTIME_UNIVERSE_H

#include "types/integer.h"

class Universe {
public:
    static Integer *True;
    static Integer *False;
    static Object *None;
    static void genesis();
    static void destroy();
};

#endif // PYTHONVM_RUNTIME_UNIVERSE_H
