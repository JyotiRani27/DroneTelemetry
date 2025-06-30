// ======================= Logger.cpp =======================
#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mu);
    std::cout << "[LOG] " << message << std::endl;
}