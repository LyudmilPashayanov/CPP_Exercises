#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	static constexpr const char* defaultName = "unknown account";
	static constexpr double defaultBalance = 0.0;
protected:
	std::string name;
	double balance;
public:
	friend std::ostream& operator<<(std::ostream &sos, const Account& account);
	void operator+=(double moneyToAdd);
	void operator-=(double moneyToGet);
	Account(std::string accountName = defaultName, double accountBalance=defaultBalance);
	bool Deposit(double moneyToAdd);
	bool Withdraw(double moneyToGet);
	double GetBalance() const;
};

