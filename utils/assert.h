//
// Created by xuliang on 2021/9/7.
//

#ifndef PYTHONVM_UTILS_ASSERT_H
#define PYTHONVM_UTILS_ASSERT_H

#include <iostream>

#ifdef NDEBUG
#define ASSERT(COND) void;
#else
#define ASSERT(cond)                                                           \
    if (cond) {                                                                \
    } else {                                                                   \
        std::cout << "Assertion failed: " << #cond << std::endl;               \
        std::cout << "at " << __FILE__ << ":" << __LINE__ << std::endl;        \
        std::exit(2);                                                          \
    }
#endif

#endif // PYTHONVM_UTILS_ASSERT_H
