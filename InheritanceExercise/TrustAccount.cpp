#include "TrustAccount.h"

TrustAccount::TrustAccount(string accountName, double accountBalance, double accountIntRate) : SavingsAccount(accountIntRate, accountName, accountBalance)
{
}

bool TrustAccount::Deposit(double moneyToAdd)
{
	if(moneyToAdd >= 5000)
	{
		moneyToAdd += 50;
	}
	return SavingsAccount::Deposit(moneyToAdd);
}

void TrustAccount::operator+=(double moneyToAdd)
{
	Deposit(moneyToAdd);
}

void TrustAccount::operator-=(double moneyToGet)
{
	Withdraw(moneyToGet);
}

bool TrustAccount::Withdraw(double moneyToGet)
{
	withdrawCounter++;
	if(withdrawCounter >= maxWithdraws)
	{
		std::cout << "You can't WITHDRAW more than 3 times.";
		return false;
	}
	double maxWithdrawMoney = balance * (maxWithdrawPercentage/100.0);
	if(moneyToGet > maxWithdrawMoney)
	{
		std::cout << "You can't WITHDRAW more than " << maxWithdrawPercentage <<"% (" << maxWithdrawMoney << "$) of your current balance.";
		return false;
	}

	return SavingsAccount::Withdraw(moneyToGet);

}
