#pragma once

#include <iostream>

#include <fmt/core.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_GRAY     "\x1b[90m"
#define ANSI_COLOR_RESET    "\x1b[0m"

namespace Logger {

    enum LogLevel {
        INFO,
        ERROR,
        DEBUG
    };

    namespace {
        std::string suffix(LogLevel level) {
            switch (level) {
                case INFO:
                    return ANSI_COLOR_GREEN "INF | " ANSI_COLOR_RESET;
                case ERROR:
                    return ANSI_COLOR_RED "ERR | " ANSI_COLOR_RESET;
                case DEBUG:
                    return ANSI_COLOR_YELLOW "DEB | " ANSI_COLOR_RESET;
                default:
                    return ANSI_COLOR_GRAY "UNK | " ANSI_COLOR_RESET;
            }
        }
    }

    template<typename... T>
    inline void Log(LogLevel level, std::string_view format, T... args) {
        auto formatted = fmt::format(format, args...);
        std::cout << suffix(level) << formatted << std::endl;
    };

    template<typename T>
    inline void Log(LogLevel level, T arg) {
        std::cout << suffix(level) << arg << std::endl;
    };


    inline void Log(LogLevel level, std::string_view message) {
        std::cout << suffix(level) << message << std::endl;
    };
};