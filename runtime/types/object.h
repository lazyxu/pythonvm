//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_RUNTIME_TYPES_OBJECT_H
#define PYTHONVM_RUNTIME_TYPES_OBJECT_H

class Object {
public:
    virtual void print();
    virtual Object *add(Object *o);
};

#endif // PYTHONVM_RUNTIME_TYPES_OBJECT_H
