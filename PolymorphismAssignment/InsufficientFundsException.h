#pragma once
#include <exception>
#include "Account.h"

class InsufficientFundsException : std::exception
{
private:
	std::string errorMessage;
public:
	InsufficientFundsException(const std::string &message) noexcept;
	~InsufficientFundsException() = default;
	virtual const char* what() const override;
};

