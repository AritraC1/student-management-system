#include <iostream>
#include "logger.hpp"

void Logger::log(LogLevel level, const std::string& message) {
    switch(level) {
        case LogLevel::INFO:
            std::cout << "[INFO] ";
            break;

        case LogLevel::WARNING:
            std::cout << "[WARNING] ";
            break;

        case LogLevel::ERROR:
            std::cout << "[ERROR] ";
            break;

        case LogLevel::DEBUG:
            std::cout << "[DEBUG] ";
            break;
    }

    std::cout << message << std::endl;
}