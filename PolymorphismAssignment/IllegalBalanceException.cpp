#include "IllegalBalanceException.h"

const char* IllegalBalanceException::what() const 
{
	return "You can not input a balance, less than 0.";
}

