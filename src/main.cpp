#include "logging/logger.hpp"
#include "app/app.hpp"

int main() {
    Logger::init("logs/log-file.txt");
    Logger::log(LogLevel::INFO, "Application started");

    Application app;
    app.run();

    return 0;
}