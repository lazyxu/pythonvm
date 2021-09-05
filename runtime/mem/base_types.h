//
// Created by xuliang on 2021/9/3.
//

#ifndef PYTHONVM_RUNTIME_MEM_BASE_TYPES_H
#define PYTHONVM_RUNTIME_MEM_BASE_TYPES_H

#include <unordered_map>
#include <vector>

template <typename T> using ArrayList = std::vector<T>;
template <typename K, typename V> using Map = std::unordered_map<K, V>;

#endif // PYTHONVM_RUNTIME_MEM_BASE_TYPES_H
