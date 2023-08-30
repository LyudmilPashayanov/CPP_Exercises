#include "Account.h"
#include "InsufficientFundsException.h"

Account::Account(std::string accountName, double accountBalance, AccountType accountType) : data{ AccountData(accountName, accountBalance) }, type{accountType}
{
	if (data.balance <0)
	{
		throw IllegalBalanceException();	
	}
}

bool Account::Deposit(double moneyToAdd)
{
	data.balance += moneyToAdd;
	return true;
}

bool Account::Withdraw(double moneyToGet)
{
	if (data.balance - moneyToGet < 0)
	{
		throw InsufficientFundsException("You have insufficient funds. You can't withdraw money from account with name: " + GetName());
	}
	data.balance -= moneyToGet;
	return true;
}

void Account::operator+=(double moneyToAdd)
{
	this->Deposit(moneyToAdd);
}

void Account::operator-=(double moneyToGet)
{
	this->Withdraw(moneyToGet);
}

void Account::ToTextData(std::ostream& os) const
{
}

bool Account::operator<(const Account& rhs) const
{
	return this->GetBalance() < rhs.GetBalance();
}

bool Account::operator>(const Account& rhs) const
{
	return this->GetBalance() > rhs.GetBalance();
}




