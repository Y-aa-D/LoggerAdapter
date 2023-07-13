#include "Logger.h"
#include "ILogger.h"
#include "LoggerAdapter.h"

int main()
{
    std::unique_ptr<Logger> originaLogger = std::make_unique<Logger>();
    originaLogger->log("Original message", "log.txt");

    Logger* originalLogger = new Logger();
    std::unique_ptr<ILogger> loggerAdapter = std::make_unique<LoggerAdapter>(originalLogger, "key", "log.txt");
    loggerAdapter->logEncrypted("Encrypted message");

    return 0;
}