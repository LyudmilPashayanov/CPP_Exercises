#include "AccountsUtil.h"

void Deposit(vector<Account> &accounts, double amountToDeposit)
{
	for (Account &acc : accounts)
	{
		if(acc.Deposit(amountToDeposit))
		{
			std::cout << "Successful deposit: " << acc << std::endl;
		}
		else
		{
			std::cout << "Unsuccessful deposit: " << acc << std::endl;
		}
	}
}

void Withdraw(std::vector<Account>& accounts, double amountToWithdraw)
{
	for (Account &acc : accounts)
	{
		if (acc.Withdraw(amountToWithdraw))
		{
			std::cout << "Successful Withdraw: " << acc << std::endl;
		}
		else
		{
			std::cout << "Unsuccessful Withdraw: " << acc << std::endl;
		}
	}
}

void Display(std::vector<Account>& accounts)
{
	int i = 0;
	for (Account acc : accounts)
	{
		std::cout << ++i << ". " << acc << std::endl;
	}
}
