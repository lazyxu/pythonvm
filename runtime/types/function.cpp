//
// Created by xuliang on 2021/9/7.
//

#include "function.h"

FunctionKlass::FunctionKlass() {}

FunctionKlass *FunctionKlass::klass = nullptr;

FunctionKlass *FunctionKlass::get_instance() {
    if (klass == nullptr) {
        klass = new FunctionKlass();
    }
    return klass;
}

void FunctionKlass::print(Object *o) {
    auto *oo = dynamic_cast<FunctionObject *>(o);

    ASSERT(oo != nullptr && oo->klass() == this);

    std::cout << "<function: " << oo->func_name()->value() << ">" << std::endl;
}

FunctionObject::FunctionObject(Object *o) {
    code_object_ = dynamic_cast<CodeObject *>(o);
    set_klass(FunctionKlass::get_instance());
}
