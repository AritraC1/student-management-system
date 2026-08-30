#pragma once

#include <string>

#include "log_level.hpp"

class Logger {
    public:
        static void log(LogLevel level, const std::string& message);
};