#pragma once
#include <ctime>
#include <string>
#include <fstream>
#include <mutex>

class Logger
{
public:

    void log(const std::string& message, const std::string& filePath);

    ~Logger() = default;

private:

    std::mutex mutex_;
    std::string getCurrentTime() const;
};