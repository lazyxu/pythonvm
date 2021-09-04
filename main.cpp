//
// Created by xuliang on 2021/9/2.
//

#include "file/binary_file_parser.h"
#include "utils/buffered_input_stream.h"
#include "utils/logger.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        LOG(FATAL) << "vm need a parameter: filename";
    }

    BufferedInputStream stream(argv[1]);
    BinaryFileParser parser(&stream);
    CodeObject *object = parser.parse();
    return 0;
}
