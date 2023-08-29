#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string accountName, double accountBalance) : Account(accountName, accountBalance)
{
}

bool CheckingAccount::Withdraw(double moneyToGet)
{
	moneyToGet += withdrawFee;
	return Account::Withdraw(moneyToGet);
}

bool CheckingAccount::Deposit(double moneyToAdd)
{
	return Account::Deposit(moneyToAdd);
}

void CheckingAccount::Print(std::ostream& os) const
{
	os << "Checking account is bla bla ";
}
