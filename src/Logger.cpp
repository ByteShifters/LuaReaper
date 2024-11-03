#include "Logger.h"

void Logger::log(LogLevel level, const std::string& message) {
    std::cout << logLevelToString(level) << ": " << currentTime() << " - " << message << std::endl;
}

std::string Logger::currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string Logger::logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:   return "(INF)";
        case LogLevel::ERROR:  return "(ERR)";
        case LogLevel::DEBUG:  return "(DBG)";
        case LogLevel::SYSTEM: return "(SYS)";
        case LogLevel::DUMP:   return "(DMP)";
        case LogLevel::CLIENT: return "(CLT)";
        default:               return "(UNK)";
    }
}
