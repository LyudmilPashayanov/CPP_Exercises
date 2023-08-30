#include <iostream>
#include <sstream>
#include <iomanip> 
#include "TrustAccount.h"
#include "InsufficientFundsException.h"

TrustAccount::TrustAccount(std::string accountName, double accountBalance, double accountIntRate, int accountWithdrawCounter) : SavingsAccount(accountName, accountBalance, accountIntRate), withdrawCounter{ accountWithdrawCounter }
{
	std::cout << "Created as a Trust account"<<std::endl;
	type = trust;
}

bool TrustAccount::Deposit(double moneyToAdd)
{
	if (moneyToAdd >= 5000)
	{
		moneyToAdd += 50;
	}
	return SavingsAccount::Deposit(moneyToAdd);
}

bool TrustAccount::Withdraw(double moneyToGet)
{
	withdrawCounter++;
	if (withdrawCounter >= maxWithdraws)
	{
		throw InsufficientFundsException("You can't WITHDRAW more than 3 times from account with name: " + GetName());
	}
	double maxWithdrawMoney = GetBalance() * (maxWithdrawPercentage / 100.0);
	if (moneyToGet > maxWithdrawMoney)
	{
		std::stringstream formattedWithdrawPercentage;
		std::stringstream formattedWithdrawMoney;
		formattedWithdrawPercentage << std::fixed << std::setprecision(2) << maxWithdrawPercentage; 
		formattedWithdrawMoney << std::fixed << std::setprecision(2) << maxWithdrawMoney;
		std::string errorMessage = "You can't WITHDRAW more than " + formattedWithdrawPercentage.str() + "% (" + formattedWithdrawMoney.str() + "$) of your current balance from account: " + GetName();
		throw InsufficientFundsException(errorMessage);
	}

	return SavingsAccount::Withdraw(moneyToGet);
}

std::string TrustAccount::Print() const
{
	std::stringstream formattedBalance;
	formattedBalance << std::fixed << std::setprecision(2) << GetBalance();
	return "Trust account [" + GetName() + "] with funds of: " + formattedBalance.str() + " $.";
}

void TrustAccount::ToTextData(std::ostream& os) const
{
	os << type << " \"" << GetName() << "\" " << GetBalance() << " " << GetIntRate() << " " << withdrawCounter;
}
