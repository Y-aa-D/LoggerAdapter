#include "Logger.h"

void Logger::log(const std::string& message, const std::string& filePath) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::ofstream logfile(filePath, std::ios::app);
    if (logfile.is_open()) {
        logfile << getCurrentTime() << " " << message << std::endl;
        logfile.close();
    }
}

std::string Logger::getCurrentTime() const {
    time_t now = time(0);
    struct tm timeinfo;
    char buffer[80];
    localtime_s(&timeinfo, &now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return buffer;
}