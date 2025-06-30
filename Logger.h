// ======================= Logger.h =======================
#pragma once
#include <iostream>
#include <mutex>

class Logger {
public:
    static Logger& getInstance();
    void log(const std::string& message);

private:
    Logger() = default;
    std::mutex mu;
};