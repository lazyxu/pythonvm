//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_OBJECT_H
#define PYTHONVM_RUNTIME_TYPES_OBJECT_H

class Object {
public:
    virtual void print();
    virtual Object *add(Object *o);
    virtual Object *less(Object *o);
    virtual Object *le(Object *o);
    virtual Object *eq(Object *o);
    virtual Object *ne(Object *o);
    virtual Object *greater(Object *o);
    virtual Object *ge(Object *o);
};

#endif // PYTHONVM_RUNTIME_TYPES_OBJECT_H
