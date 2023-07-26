#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int amount{ 0 };
	
	int dollar{ 0 };
	int quarter{ 0 };
	int dime{ 0 };
	int nickel{ 0 };
	int penny{ 0 };

	cout << "Enter the amount in cents: " << endl;
	cin >> amount;

	dollar = amount / 100;
	amount -= dollar * 100;

	quarter =  amount / 25;
	amount -= quarter * 25;

	dime = amount / 10;
	amount -= dime * 10;

	nickel = amount / 5;
	amount -= nickel * 5;

	penny = amount;

	cout << "dollars : "<< dollar << endl;
	cout << "quarters : "<< quarter << endl;
	cout << "dimes : "<< dime << endl;
	cout << "nickel : "<< nickel << endl;
	cout << "penny	: "<< penny << endl;
	return 0;
}
