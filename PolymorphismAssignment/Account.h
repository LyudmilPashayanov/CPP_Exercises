#pragma once
#include <iostream>
#include <string>
#include "IPersistable.h"
#include "IllegalBalanceException.h"


enum AccountType
{
	savings,
	trust,
	checking
};

struct AccountData
{
public:
	AccountData(std::string accName, double accBalance) : name{ accName }, balance{accBalance}
	{}
	std::string name;
	double balance;
};

class Account : public IPersistable
{
private:
	AccountData data;
protected:
	AccountType type;
public:
	Account(std::string accountName, double accountBalance, AccountType accountType);
	virtual ~Account() = default;

	std::string GetName() const { return data.name; }
	double GetBalance() const { return data.balance; }

	virtual bool Deposit(double moneyToAdd) = 0;
	virtual bool Withdraw(double moneyToGet) = 0;
	virtual void operator+=(double moneyToAdd);
	virtual void operator-=(double moneyToGet);
	virtual std::string Print() const override=0;
	virtual void ToTextData(std::ostream& os) const override=0;

};

