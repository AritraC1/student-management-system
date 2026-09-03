#pragma once
#include <string>

// Represents the severity or type of a log message.
enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

// Converts a LogLevel enum value into its corresponding string.
// The function is marked inline so it can safely be defined in a header file.
inline std::string log_level_to_string(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::DEBUG:   return "DEBUG";
    }

    // Fallback for an invalid or unexpected LogLevel value
    return "UNKNOWN";
}