#pragma once
#include <exception>

class IllegalBalanceException : std::exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default ;
	virtual const char* what() const override;
};

