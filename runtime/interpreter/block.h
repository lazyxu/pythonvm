//
// Created by xuliang on 2021/9/5.
//

#ifndef PYTHONVM_RUNTIME_INTERPRETER_BLOCK_H
#define PYTHONVM_RUNTIME_INTERPRETER_BLOCK_H

class Block {
public:
    Block(unsigned char type, uint32_t target, uint32_t level)
        : type_(type), target_(target), level_(level) {}
    unsigned char type_;
    uint32_t target_;
    uint32_t level_;
};

#endif // PYTHONVM_RUNTIME_INTERPRETER_BLOCK_H
