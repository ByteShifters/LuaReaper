#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

class Logger {
public:
    enum class LogLevel { INFO, ERROR, DEBUG, SYSTEM, DUMP, CLIENT };

    Logger() = default;

    static void log(LogLevel level, const std::string& message);

private:
    static std::string currentTime();
    static std::string logLevelToString(LogLevel level);
};

#endif