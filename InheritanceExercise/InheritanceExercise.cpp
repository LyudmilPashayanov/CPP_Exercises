#include <iostream>
#include <vector>
#include "AccountsUtil.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

int main()
{
	SavingsAccount sAccount(5,"savings account");
	Account normalAccount("normal account",500);
	sAccount.Deposit(100);
	
	vector<Account> vec {sAccount, normalAccount};

	Display(vec);
	Withdraw(vec, 100);
	Display(vec);
	Deposit(vec, 20);
	Display(vec);
	Withdraw(vec, 60);
	Display(vec);

	std::cout << sAccount;

	sAccount += 100;
	std::cout << sAccount;

	CheckingAccount checkAcc;
	checkAcc.Deposit(10);
	checkAcc -= 9.5;
	std::cout << checkAcc;


	TrustAccount trustAcc;
	trustAcc.Deposit(5000);
	trustAcc.Withdraw(1100);
	return 0;
}
