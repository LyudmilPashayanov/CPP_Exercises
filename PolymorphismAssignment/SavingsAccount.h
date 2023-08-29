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
	SavingsAccount(std::string accountName = defaultName, double accountBalance = defaultBalance, double accountIntRate = defaultIntRate);
	virtual bool Deposit(double moneyToAdd) override;
	virtual bool Withdraw(double moneyToGet) override;
	virtual std::string Print() const override;
	virtual void ToTextData(std::ostream& os) const override;

	virtual ~SavingsAccount() = default;

	virtual double GetIntRate() const { return intRate; }
};

