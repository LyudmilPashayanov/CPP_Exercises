#include "Account.h"

void Account::operator+=(double moneyToAdd)
{
	this->Deposit(moneyToAdd);
}

void Account::operator-=(double moneyToGet)
{
	this->Withdraw(moneyToGet);
}

Account::Account(std::string accountName, double accountBalance) : name{accountName},balance{accountBalance}
{
	std::cout << "acount created with name: '" << name << "' and balance: '" << balance <<"' "<< std::endl;
}


bool Account::Deposit(double moneyToAdd)
{
	balance += moneyToAdd;
	std::cout << "acount with name: '" << name << "' current balance is: '" << balance << "' " << std::endl;
	return true;
}

bool Account::Withdraw(double moneyToGet)
{
	if(balance - moneyToGet < 0)
	{
		std::cout << "acount with name: '" << name << "' doesn't have enough funds to withdraw. Current balance is: '" << balance << "' " << std::endl;
		return false;
	}
	balance -= moneyToGet;
	std::cout << "WITHDRAW acount with name: '" << name << "' now has is: '" << balance << "' balance" << std::endl;
	return true;
}

double Account::GetBalance()const
{
	return balance;
}

std::ostream& operator<<(std::ostream &os, const Account& account)
{
	os <<"Account with name '"<< account.name <<"' has a balance of: " << account.GetBalance() << std::endl;
	return os;
}


