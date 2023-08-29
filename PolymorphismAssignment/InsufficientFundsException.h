#pragma once
#include <exception>

class InsufficientFundsException : std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	~InsufficientFundsException() = default;
	virtual const char* what() const override;
};

