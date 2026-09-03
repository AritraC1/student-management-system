#include "logging/logger.hpp"
#include "app/app.hpp"

int main() {
    // Log
    Logger::init("logs/log-file.txt");
    Logger::log(LogLevel::INFO, "Application started");

    // Main app run
    Application app;
    app.run();

    return 0;
}