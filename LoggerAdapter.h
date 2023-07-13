#pragma once

#include "ILogger.h"
#include "Logger.h"

class LoggerAdapter : public ILogger
{
public:

    LoggerAdapter(Logger* originalLogger, const std::string& encryptionKey, const std::string& filePath)
        : originalLogger(originalLogger), encryptionKey(encryptionKey), filePath(filePath) {}

    ~LoggerAdapter() {
        delete originalLogger;
    }

private:

    Logger* originalLogger;
    std::string filePath;
    std::string encryptionKey;
    int counter = 0;

    void logEncrypted(const std::string& message) override;
    std::string encryptMessage(const std::string& message);
};