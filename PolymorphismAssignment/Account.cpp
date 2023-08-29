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
		throw InsufficientFundsException();
	}
	data.balance -= moneyToGet;
	return true;
}

//std::string Account::Print() const
//{
//	return "basic account";
//}
//
//void Account::ToTextData(std::ostream& os) const
//{
//	os << type << " \"" << GetName() << "\" " << GetBalance();
//}

void Account::operator+=(double moneyToAdd)
{
	this->Deposit(moneyToAdd);
}

void Account::operator-=(double moneyToGet)
{
	this->Withdraw(moneyToGet);
}




