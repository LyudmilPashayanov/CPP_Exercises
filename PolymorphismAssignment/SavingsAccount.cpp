#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string accountName, double accountBalance, double accountIntRate) : Account(accountName, accountBalance, savings), intRate{ accountIntRate }
{
	std::cout << "Savings account created with name: '" << GetName() << "', balance: '" << GetBalance() << "' and Interest Rate of: " << intRate << std::endl;
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

std::string SavingsAccount::Print() const
{
	return "Savings account [" + GetName() +"] with funds of: " + std::to_string(GetBalance());
}

void SavingsAccount::ToTextData(std::ostream& os) const
{
	os << type << " \"" << GetName() << "\" " << GetBalance() << " " << GetIntRate();
}
