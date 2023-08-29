#include <iostream>
#include <vector>
#include "AccountsUtil.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

int main()
{
	Account * savings = new SavingsAccount();
	Account * trust = new TrustAccount();
	Account * checking = new CheckingAccount();

	vector<Account*> vec {savings,trust, checking};
	Deposit(vec, 5500);
	Withdraw(vec, 100);
	return 0;
}
