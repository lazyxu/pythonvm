//
// Created by xuliang on 2021/9/2.
//

#ifndef PYTHONVM_UTILS_LOGGER_H
#define PYTHONVM_UTILS_LOGGER_H

#include <iostream>
#include <sstream>

#define LEVEL(level) level,

#define LOG_LEVEL_LIST                                                         \
    LEVEL(DEBUG)                                                               \
    LEVEL(INFO)                                                                \
    LEVEL(WARN)                                                                \
    LEVEL(ERROR)                                                               \
    LEVEL(FATAL)

enum Level { LOG_LEVEL_LIST };

#undef LEVEL

#define LEVEL(level) #level,

const std::string LevelName[] = {LOG_LEVEL_LIST};

#undef LEVEL

void SetLogLevel(Level level);

bool IsLogLevelEnabled(Level level);

class Message {
public:
    Message(Level level) : level_(level){};

    ~Message();

    std::stringstream &GetStream() { return stream_; }

private:
    std::stringstream stream_;
    Level level_;
};

#define LOG(LEVEL) IsLogLevelEnabled(LEVEL) && Message(LEVEL).GetStream()

#endif // PYTHONVM_UTILS_LOGGER_H
