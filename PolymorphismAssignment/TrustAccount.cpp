#include "TrustAccount.h"

TrustAccount::TrustAccount(string accountName, double accountBalance, double accountIntRate) : SavingsAccount(accountIntRate, accountName, accountBalance)
{
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
		std::cout << "You can't WITHDRAW more than 3 times.";
		return false;
	}
	double maxWithdrawMoney = balance * (maxWithdrawPercentage / 100.0);
	if (moneyToGet > maxWithdrawMoney)
	{
		std::cout << "You can't WITHDRAW more than " << maxWithdrawPercentage << "% (" << maxWithdrawMoney << "$) of your current balance.";
		return false;
	}

	return SavingsAccount::Withdraw(moneyToGet);
}

void TrustAccount::Print(std::ostream& os) const
{
	os << "Trust account is bla bla ";
}
