#include "TrustAccount.h"
#include "InsufficientFundsException.h"

TrustAccount::TrustAccount(std::string accountName, double accountBalance, double accountIntRate, int accountWithdrawCounter) : SavingsAccount(accountName, accountBalance, accountIntRate), withdrawCounter{ accountWithdrawCounter }
{
	std::cout << " +++ this is a Trust account"<<std::endl;
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
		std::cout << "You can't WITHDRAW more than 3 times." << std::endl;
		throw InsufficientFundsException();
	}
	double maxWithdrawMoney = GetBalance() * (maxWithdrawPercentage / 100.0);
	if (moneyToGet > maxWithdrawMoney)
	{
		std::cout << "You can't WITHDRAW more than " << maxWithdrawPercentage << "% (" << maxWithdrawMoney << "$) of your current balance." << std::endl;
		throw InsufficientFundsException();
	}

	return SavingsAccount::Withdraw(moneyToGet);
}

std::string TrustAccount::Print() const
{
	return "Trust account [" + GetName() + "] with funds of: " + std::to_string(GetBalance());
}

void TrustAccount::ToTextData(std::ostream& os) const
{
	os << type << " \"" << GetName() << "\" " << GetBalance() << " " << GetIntRate() << " " << withdrawCounter;
}
