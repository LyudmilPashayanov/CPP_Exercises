#include "Account.h"
#include <iostream>


Account::Account() : balance{0.0}
{ }
Account::Account(double startingBalance): balance(startingBalance)
{ }
bool Account::Deposit(double deposit_amount)
{
	if (deposit_amount < 0)
	{
		return false;
	}
	
	balance += deposit_amount;
	return true;
}

bool Account::Withdraw(double withdraw_amount)
{ 
	 if(balance-withdraw_amount < 0)
	 {
		 cout << "Insufficient funds" << endl;
		 return false;
	 }
	
	 balance -= withdraw_amount;
	 return true;
}

ostream& operator<<(std::ostream& stream, const Account& account)
{
	return stream << "balance of account is: " << account.balance;
}
