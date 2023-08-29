#pragma once
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
private:
	static constexpr const char* defaultName = "unknown Trust account";
	static constexpr double defaultBalance = 0.0;
	int withdrawCounter = 0;
	int maxWithdraws = 4;
	double maxWithdrawPercentage = 20;
public:
	TrustAccount(string accountName= defaultName, double accountBalance= defaultBalance, double accountIntRate= defaultIntRate);
	bool Deposit(double moneyToAdd);
	void operator+=(double moneyToAdd);
	void operator-=(double moneyToGet);
	bool Withdraw(double moneyToGet);
};

