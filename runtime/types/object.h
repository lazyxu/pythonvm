//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_OBJECT_H
#define PYTHONVM_RUNTIME_TYPES_OBJECT_H

#include "../../utils/assert.h"
#include "klass.h"

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    Klass *klass() const {
        ASSERT(klass_ != nullptr);
        return klass_;
    }
    void set_klass(Klass *klass) { klass_ = klass; }

    void print() { klass_->print(this); }
    Object *add(Object *o) { return klass_->add(this, o); };
    Object *less(Object *o) { return klass_->less(this, o); };
    Object *le(Object *o) { return klass_->le(this, o); };
    Object *eq(Object *o) { return klass_->eq(this, o); };
    Object *ne(Object *o) { return klass_->ne(this, o); };
    Object *greater(Object *o) { return klass_->greater(this, o); };
    Object *ge(Object *o) { return klass_->ge(this, o); };
    Object *len() { return klass_->len(this); };

private:
    Klass *klass_;
};

#endif // PYTHONVM_RUNTIME_TYPES_OBJECT_H
