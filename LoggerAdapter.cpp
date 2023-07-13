#include "LoggerAdapter.h"

void LoggerAdapter::logEncrypted(const std::string& message) {
    std::string encryptedMessage = encryptMessage(message);
    originalLogger->log(encryptedMessage, filePath);
}

std::string LoggerAdapter::encryptMessage(const std::string& message) {
    std::string encryptedMessage;
    for (char c : message) {
        encryptedMessage += c ^ encryptionKey[counter % encryptionKey.length()];
        counter++;
    }
    return encryptedMessage;
}