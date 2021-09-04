//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_FILE_CODE_OBJECT_H
#define PYTHONVM_FILE_CODE_OBJECT_H

#include "../runtime/mem/base_types.h"
#include "../runtime/types/object.h"
#include "../runtime/types/string.h"

class CodeObject : public Object {
public:
    int arg_count_;
    int nlocals_;
    int stack_size_;
    int flag_;

    String *bytecodes_;
    ArrayList<Object *> *names_;
    ArrayList<Object *> *consts_;
    ArrayList<Object *> *var_names_;

    ArrayList<Object *> *free_vars_;
    ArrayList<Object *> *cell_vars_;

    String *co_name_;
    String *file_name_;

    int line_no_;
    String *notable_;

    String *file_path_;

    CodeObject(int arg_count, int nlocals, int stack_size, int flag,
               String *bytecodes, ArrayList<Object *> *consts,
               ArrayList<Object *> *names, ArrayList<Object *> *var_names,
               ArrayList<Object *> *free_vars, ArrayList<Object *> *cell_vars,
               String *file_name, String *co_name, int line_no, String *notable,
               String *file_path)
        : arg_count_(arg_count), nlocals_(nlocals), stack_size_(stack_size),
          flag_(flag), bytecodes_(bytecodes), names_(names), consts_(consts),
          var_names_(var_names), free_vars_(free_vars), cell_vars_(cell_vars),
          co_name_(co_name), file_name_(file_name), line_no_(line_no),
          notable_(notable), file_path_(file_path) {}
};

#endif // PYTHONVM_FILE_CODE_OBJECT_H
