//
// Created by xuliang on 2021/9/2.
//

#include "logger.h"

static Level gLevel = FATAL;

void SetLogLevel(Level level) { gLevel = level; }

bool IsLogLevelEnabled(Level level) { return level >= gLevel; }

Message::~Message() {
    std::cout << "[" << LevelName[level_] << "] " << stream_.str() << std::endl;
    if (level_ == FATAL) {
        std::abort();
    }
}
