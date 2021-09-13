//
// Created by xuliang on 2021/9/5.
//

#ifndef PYTHONVM_RUNTIME_KLASS_KLASS_H
#define PYTHONVM_RUNTIME_KLASS_KLASS_H

class Object;
class String;

class Klass {
public:
    Klass() = default;

    void set_name(String *s) { name_ = s; }
    String *name() { return name_; }
    virtual void print(Object *o);

    virtual Object *less(Object *x, Object *y);
    virtual Object *le(Object *x, Object *y);
    virtual Object *eq(Object *x, Object *y);
    virtual Object *ne(Object *x, Object *y);
    virtual Object *greater(Object *x, Object *y);
    virtual Object *ge(Object *x, Object *y);

    virtual Object *add(Object *x, Object *y);
    virtual Object *sub(Object *x, Object *y);
    virtual Object *mul(Object *x, Object *y);
    virtual Object *div(Object *x, Object *y);
    virtual Object *mod(Object *x, Object *y);

    virtual Object *len(Object *o);

private:
    String *name_{};
};

#endif // PYTHONVM_RUNTIME_KLASS_KLASS_H
