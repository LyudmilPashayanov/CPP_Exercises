#include "Account.h"

Account::Account(std::string accountName, double accountBalance) : name{ accountName }, balance{ accountBalance }
{}


bool Account::Deposit(double moneyToAdd)
{
	balance += moneyToAdd;
	std::cout << "DEPOSIT acount with name: '" << name << "' current balance is: '" << balance << "' " << std::endl;
	return true;
}

bool Account::Withdraw(double moneyToGet)
{
	if (balance - moneyToGet < 0)
	{
		std::cout << "FAIL WITHDRAW acount with name: '" << name << "' doesn't have enough funds to withdraw. Current balance is: '" << balance << "' " << std::endl;
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

void Account::Print(std::ostream& stream) const
{
	stream << "basic account";
}

void Account::operator+=(double moneyToAdd)
{
	this->Deposit(moneyToAdd);
}

void Account::operator-=(double moneyToGet)
{
	this->Withdraw(moneyToGet);
}




