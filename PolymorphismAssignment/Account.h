#pragma once
#include <iostream>
#include <string>
#include "IPrintable.h"
using namespace std;

class Account : public IPrintable
{
protected:
	std::string name;
	double balance;
public:
	Account(std::string accountName, double accountBalance);
	virtual bool Deposit(double moneyToAdd) = 0;
	virtual bool Withdraw(double moneyToGet) = 0;
	virtual void operator+=(double moneyToAdd);
	virtual void operator-=(double moneyToGet);
	virtual double GetBalance() const;
	virtual void Print(std::ostream& stream) const override;
	virtual ~Account() = default;
};

