#pragma once

#include <string>

class ILogger
{
public:
	virtual ~ILogger() {}
    virtual void logEncrypted(const std::string& message) = 0;
};