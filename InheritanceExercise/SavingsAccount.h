#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	double intRate;
	static constexpr const char* defaultName = "unknown savings account";
	static constexpr double defaultBalance = 0.0;
protected:
	static constexpr double defaultIntRate = 0.0;

public:
	SavingsAccount(double accountIntRate = defaultIntRate, std::string accountName=defaultName, double accountBalance=defaultBalance);
	bool Deposit(double moneyToAdd);
	void operator+=(double moneyToAdd);
	void operator-=(double moneyToGet);
};

