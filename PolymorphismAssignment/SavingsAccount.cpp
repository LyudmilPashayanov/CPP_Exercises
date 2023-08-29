#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double accountIntRate, std::string accountName, double accountBalance) : Account(accountName, accountBalance), intRate{ accountIntRate }
{
	std::cout << "Savings account created with name: '" << name << "', balance: '" << balance << "' and Interest Rate of: " << intRate << std::endl;
}

bool SavingsAccount::Deposit(double moneyToAdd)
{
	moneyToAdd += moneyToAdd * (intRate / 100);
	return Account::Deposit(moneyToAdd);
}

bool SavingsAccount::Withdraw(double moneyToGet)
{
	return Account::Withdraw(moneyToGet);
}

void SavingsAccount::Print(std::ostream& os) const
{
	os << "Savings account is bla bla ";
}
