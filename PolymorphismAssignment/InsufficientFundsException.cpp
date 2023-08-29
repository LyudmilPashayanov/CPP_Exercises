#include "InsufficientFundsException.h"

const char* InsufficientFundsException::what() const
{
    return "You have insufficient funds. You can't withdraw money from this account.";
}
