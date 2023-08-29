#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	double intRate;
	static constexpr const char* defaultName = "unknown savings account";
	static constexpr double defaultBalance = 0.0;
protected:
	static constexpr double defaultIntRate = 5.0;

public:
	SavingsAccount(double accountIntRate = defaultIntRate, std::string accountName = defaultName, double accountBalance = defaultBalance);
	virtual bool Deposit(double moneyToAdd) override;
	virtual bool Withdraw(double moneyToGet) override;
	virtual void Print(std::ostream& os) const override;

	virtual ~SavingsAccount() = default;

};

