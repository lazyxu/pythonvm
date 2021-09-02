//
// Created by xuliang on 2021/9/2.
//

#include "utils/buffered_input_stream.h"
#include "utils/logger.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        LOG(FATAL) << "vm need a parameter: filename";
    }

    BufferedInputStream stream(argv[1]);
    LOG(INFO) << "magic number is 0x" << hex << stream.read_int();
    return 0;
}
