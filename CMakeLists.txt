cmake_minimum_required(VERSION 3.14)
project(pythonvm)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_CXX_FLAGS "-O0 -Wall -g -ggdb")

SET(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

add_executable(pythonvm
        main.cpp
        utils/logger.cpp
        runtime/universe.cpp
        runtime/types/klass.cpp
        runtime/types/object.cpp
        runtime/types/string.cpp
        runtime/types/integer.cpp
        runtime/interpreter/bytecode.cpp
        runtime/interpreter/interpreter.cpp
        runtime/interpreter/frame_object.cpp
        file/code_object.cpp
        file/binary_file_parser.cpp
        )
