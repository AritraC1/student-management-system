#pragma once

#include <string>
#include <fstream>

#include "log_level.hpp"

// Logger is a utility class responsible for writing log messages
class Logger {
    static int sno;
    
    // Output file stream used to write log messages to a file.
    static std::ofstream log_file;
    
    // Returns the current timestamp as a string. 
    // Kept private because users of Logger don't need to call it directly.
    static std::string get_timestamp(); 

    public:
        // Initializes the logger and opens the specified file.
        static void init(const std::string& file_path);

        // Writes a log message with the specified log level.
        static void log(LogLevel level, const std::string& message);
};