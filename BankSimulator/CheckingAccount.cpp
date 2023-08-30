#include <iostream>
#include <sstream>
#include <iomanip> 
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string accountName, double accountBalance) : Account(accountName, accountBalance,checking)
{
	std::cout << "Checking account created with name: '" << GetName() << "', balance: '" << GetBalance() <<"'" << std::endl;
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

std::string CheckingAccount::Print() const
{
	std::stringstream formattedBalance;
	formattedBalance << std::fixed << std::setprecision(2) << GetBalance();
	return "Checking account [" + GetName() + "] with funds of: " + formattedBalance.str() + " $.";
}

void CheckingAccount::ToTextData(std::ostream& os) const
{
	os << type << " \"" << GetName() << "\" " << GetBalance() << " " << withdrawFee;
}
