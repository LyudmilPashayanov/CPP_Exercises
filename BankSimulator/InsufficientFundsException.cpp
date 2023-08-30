#include "InsufficientFundsException.h"
#include <sstream>

InsufficientFundsException::InsufficientFundsException(const std::string &message) noexcept
{
    errorMessage = message;
}

const char* InsufficientFundsException::what() const
{
    return errorMessage.c_str();
}
