#include "IllegalBalanceException.h"

const char* IllegalBalanceException::what() const 
{
	return "You can not create an account with a balance, less than 0.";
}

