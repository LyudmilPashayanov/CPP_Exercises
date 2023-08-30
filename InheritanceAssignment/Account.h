#pragma once

#include <iostream>
using namespace std;

class Account
{
protected:
	double balance;
public:
	Account();
	Account(double startingBalance);
	bool Deposit(double deposit_amaount);
	bool Withdraw(double withdraw_amaount);
	friend  ostream &operator<<(std::ostream& stream, const Account &account);
};

