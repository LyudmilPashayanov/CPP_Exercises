#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account () , int_rate {0.0}
{ }

SavingsAccount::SavingsAccount(double initialBalance, double interest_rate) : Account(initialBalance), int_rate{ interest_rate}
{ }

bool SavingsAccount::Deposit(double deposit_amount)
{
	if (deposit_amount < 0)
	{
		return false;
	}

	balance += deposit_amount + (deposit_amount * (int_rate/100));
	return true;
}

ostream& operator<<(std::ostream& stream, const SavingsAccount& account)
{
	return stream << "balance of savings account is: " << account.balance << " AND interest rate is: " << account.int_rate;
}
