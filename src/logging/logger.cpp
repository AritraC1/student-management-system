#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "logger.hpp"

// static members must be DEFINED once, outside the class, in the `.cpp`
int Logger::sno = 0;
std::ofstream Logger::log_file;

void Logger::init(const std::string& file_path) {
    // Open in append mode so old logs are preserved.
    log_file.open(file_path, std::ios::app);
    if (!log_file.is_open()) {
        std::cerr << "Failed to open log file: " << file_path << std::endl;
    }
}

std::string Logger::get_timestamp() {
    // Get current local time.
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);

    // Format time as YYYY-MM-DD HH:MM:SS.
    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Logger::log(LogLevel level, const std::string& message) {
    // Increment log sequence number.
    sno++;

    // Build the log entry.
    std::ostringstream entry;
    entry << sno << " | "
          << log_level_to_string(level) << " | "
          << message << " | "
          << get_timestamp();

    // Print to console.
    std::cout << entry.str() << std::endl;

    if (log_file.is_open()) {
        // Write to file and flush immediately.
        log_file << entry.str() << std::endl;
        log_file.flush();
    }
}