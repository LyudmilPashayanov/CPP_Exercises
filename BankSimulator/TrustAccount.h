#pragma once
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
private:
	static constexpr const char* defaultName = "unknown Trust account";
	static constexpr double defaultBalance = 0.0;
	static constexpr int maxWithdraws = 4;
	static constexpr double maxWithdrawPercentage = 20;

	int withdrawCounter = 0;

public:
	TrustAccount(std::string accountName = defaultName, double accountBalance = defaultBalance, double accountIntRate = defaultIntRate, int accountWithdrawCounter = 0);
	virtual bool Deposit(double moneyToAdd) override;
	virtual bool Withdraw(double moneyToGet) override;
	virtual std::string Print() const override;
	virtual void ToTextData(std::ostream& os) const override;

	virtual ~TrustAccount() = default;

};

