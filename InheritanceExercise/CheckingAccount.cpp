#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string accountName, double accountBalance) : Account(accountName, accountBalance)
{
}

bool CheckingAccount::Withdraw(double moneyToGet)
{
	moneyToGet += withdrawFee;
	return Account::Withdraw(moneyToGet);
}

void CheckingAccount::operator-=(double moneyToGet)
{
	moneyToGet += withdrawFee;
	Account::Withdraw(moneyToGet);
}
