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
	TrustAccount(string accountName = defaultName, double accountBalance = defaultBalance, double accountIntRate = defaultIntRate);
	virtual bool Deposit(double moneyToAdd) override;
	virtual bool Withdraw(double moneyToGet) override;
	virtual void Print(std::ostream& os) const override;

	virtual ~TrustAccount() = default;

};

