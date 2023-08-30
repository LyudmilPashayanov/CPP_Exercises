#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

int main()
{
	Account a1{ 100 };
	cout << a1<<endl;
	a1.Deposit(200);
	cout << a1 << endl;
	a1.Withdraw(100);
	cout << a1 << endl;
	a1.Withdraw(300);
	cout << a1 << endl;
	cout << "--------------------" << endl;

	SavingsAccount savings{ 100,5 };
	cout << savings << endl;
	savings.Deposit(200);
	cout << savings << endl;
	savings.Withdraw(100);
	cout << savings << endl;

	cout << "--------------------" << endl;



}
