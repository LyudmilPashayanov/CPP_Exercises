#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
protected:
	double int_rate;
public:
	SavingsAccount();
	SavingsAccount(double initialBalance, double interest_rate);
	bool Deposit(double deposit_amount);
	//Withdraw is inherited

	friend  ostream& operator<<(std::ostream& stream, const SavingsAccount& account);
};

