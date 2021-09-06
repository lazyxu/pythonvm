//
// Created by xuliang on 2021/9/2.
//

#include "integer.h"

#include "../universe.h"
#include <iostream>

IntegerKlass::IntegerKlass() {}

IntegerKlass *IntegerKlass::klass = nullptr;

IntegerKlass *IntegerKlass::get_instance() {
    if (klass == nullptr) {
        klass = new IntegerKlass();
    }
    return klass;
}

void IntegerKlass::print(Object *o) {
    auto *oo = dynamic_cast<Integer *>(o);

    ASSERT(oo != nullptr && oo->klass() == this);

    std::cout << oo->value();
}

Object *IntegerKlass::less(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() < yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::le(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() <= yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::eq(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() == yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::ne(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() != yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::greater(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() > yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::ge(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return xx->value() >= yy->value() ? Universe::True : Universe::False;
}

Object *IntegerKlass::add(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return new Integer(xx->value() + yy->value());
}

Object *IntegerKlass::sub(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return new Integer(xx->value() - yy->value());
}

Object *IntegerKlass::mul(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return new Integer(xx->value() * yy->value());
}

Object *IntegerKlass::div(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return new Integer(xx->value() / yy->value());
}

Object *IntegerKlass::mod(Object *x, Object *y) {
    auto *xx = dynamic_cast<Integer *>(x);
    auto *yy = dynamic_cast<Integer *>(y);

    ASSERT(xx != nullptr && (xx->klass() == (Klass *)this));
    ASSERT(yy != nullptr && (yy->klass() == (Klass *)this));

    return new Integer(xx->value() % yy->value());
}
