//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_UTILS_BUFFERED_INPUT_STREAM_H
#define PYTHONVM_UTILS_BUFFERED_INPUT_STREAM_H

#include <cstdio>
#include <iostream>

#define BUFFER_LEN 256

class BufferedInputStream {
private:
    FILE *fp;
    const char *file_path;
    char szBuffer[BUFFER_LEN]{};
    unsigned short index;

public:
    explicit BufferedInputStream(char const *file_path) {
        fp = fopen(file_path, "rb");
        if (fp == nullptr) {
            std::cout << "no such file: " << file_path << std::endl;
        }
        this->file_path = file_path;
        fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
        index = 0;
    }

    ~BufferedInputStream() { close(); }

    const char *get_file_path() { return file_path; }

    char read() {
        if (index < BUFFER_LEN)
            return szBuffer[index++];
        else {
            index = 0;
            fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
            return szBuffer[index++];
        }
    }

    int read_int() {
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;

        return b4 << 24 | b3 << 16 | b2 << 8 | b1;
    }

    double read_double() {
        char t[8];
        for (char &i : t) {
            i = read();
        }

        return *(double *)t;
    }

    void unread() { index--; }

    void close() {
        if (fp != nullptr) {
            fclose(fp);
            fp = nullptr;
        }
    }
};

#endif // PYTHONVM_UTILS_BUFFERED_INPUT_STREAM_H
