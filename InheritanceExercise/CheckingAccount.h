#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
private:
	static constexpr const char* defaultName = "unknown checking account";
	static constexpr double defaultBalance = 0.0;
	double const withdrawFee = 1.5;
public:
	CheckingAccount(string accountName = defaultName, double accountBalance=defaultBalance);
	bool Withdraw(double moneyToGet);
	void operator-=(double moneyToGet);
};

