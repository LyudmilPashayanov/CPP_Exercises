#include "AccountsUtil.h"
#include <sstream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

void Deposit(std::vector<Account*> &accounts, double amountToDeposit) // Raw pointers
{
	for (Account* acc : accounts)
	{
		if (acc->Deposit(amountToDeposit))
		{
			std::cout << "Successful deposit: " << acc->Print() << std::endl;
		}
		else
		{
			std::cout << "Unsuccessful deposit: " << acc->Print() << std::endl;
		}
	}
}

void Deposit(std::vector<std::unique_ptr<Account>> &accounts, double amountToDeposit) // Smart pointers
{
	for (std::unique_ptr<Account> &acc : accounts)
	{
		if (acc->Deposit(amountToDeposit))
		{
			std::cout << "Successful deposit: " << acc->Print() << std::endl;
		}
		else
		{
			std::cout << "Unsuccessful deposit: " << acc->Print() << std::endl;
		}
	}
}

void Withdraw(std::vector<Account*>& accounts, double amountToWithdraw)  // Raw pointers
{
	for (Account* acc : accounts)
	{
		if (acc->Withdraw(amountToWithdraw))
		{
			std::cout << "Successful Withdraw: " << acc->Print() << std::endl;
		}
	}
}

void Withdraw(std::vector<std::unique_ptr<Account>>& accounts, double amountToWithdraw) // Smart pointers
{
	for (std::unique_ptr<Account>& acc : accounts)
	{
		if (acc->Withdraw(amountToWithdraw))
		{
			std::cout << "Successful Withdraw: " << acc->Print() << std::endl;
		}
	}
}

void Display(std::vector<std::unique_ptr<Account>>& accounts)
{
	int i = 0;
	for (std::unique_ptr<Account> &acc : accounts)
	{
		std::cout << ++i << ". " << acc->Print() << std::endl;
	}
}

void WriteFileWithAccounts(std::vector<std::unique_ptr<Account>> &vec)
{
	std::ofstream ostream {"accounts.txt"};
	if (!ostream)
	{
		std::cout << "Error creating file." << std::endl;
	}
	else
	{
		for (auto& acc : vec)
		{
			ostream << *acc << std::endl;
		}
	}
	ostream.close();
}

std::vector<std::unique_ptr<Account>> ReadFileWithAccounts()
{
	std::vector<std::unique_ptr<Account>> accounts;
	std::ifstream istream {"accounts.txt"};
	if (!istream)
	{
		std::cout << "Error opening file." << std::endl;
	}
	else
	{
		std::string line;
		while (std::getline(istream, line))
		{
			std::istringstream lineStream {line};
			int accountType;
			std::string accName;
			double accBalance;

			// Get the account type.
			lineStream >> accountType;

			// Get the account name.
			size_t first = line.find("\"");
			size_t last = line.find_last_of("\"");
			accName = line.substr(first+1, last - first-1);
			
			// Prepare the line stream to read the rest of the information.
			lineStream.seekg(last+1);

			switch (accountType)
			{
			case savings:
			{
				double accIntRate;
				lineStream >> accBalance >> accIntRate;
				accounts.push_back(std::make_unique<SavingsAccount>(accName, accBalance, accIntRate));
				break;
			}
			case checking:
			{
				accounts.push_back(std::make_unique<CheckingAccount>(accName, accBalance));
				break;
			}
			case trust:
			{
				double accIntRate;
				lineStream >> accBalance >> accIntRate;
				accounts.push_back(std::make_unique<TrustAccount>(accName, accBalance, accIntRate));
				break;
			}
			default:
				break;
			}
		}
	}
	istream.close();
	return accounts;
}

double RequestBalanceFromUser()
{
	double balanceInput{ -1 };
	while (balanceInput == -1)
	{
		try
		{
			std::cout << "Please input the balance of this account:" << std::endl;
			if (std::cin >> balanceInput)
			{
				if (balanceInput < 0)
				{
					throw IllegalBalanceException();
				}
			}
			else
			{
				throw IllegalBalanceException();
			}
		}
		catch (IllegalBalanceException& ex)
		{
			balanceInput = -1;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid input: "<< ex.what() << std::endl;
		}
	}
	return balanceInput;
}


std::unique_ptr<Account> CreateAccount()
{
	std::unique_ptr<Account> account;

	std::cout << "Write the corresponding number of the type of account you would like to create:" << std::endl;
	std::cout << "1 - Savings account." << std::endl;
	std::cout << "2 - Checking account." << std::endl;
	std::cout << "3 - Trust account." << std::endl;
	int numberChosen{ 0 };
	std::string accountName;
	double accountBalance;
	while (numberChosen == 0)
	{
		std::cin >> numberChosen;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (numberChosen)
		{
		case 1:
			std::cout << "Write the name of your Savings account: " << std::endl;
			std::getline(std::cin, accountName);
			accountBalance = RequestBalanceFromUser();
			account = std::make_unique<SavingsAccount>(accountName, accountBalance);
			break;
		case 2:
			std::cout << "Write the name of your Checking account: " << std::endl;
			std::getline(std::cin, accountName);
			accountBalance = RequestBalanceFromUser();
			account = std::make_unique<CheckingAccount>(accountName, accountBalance);
			break;
		case 3:
			std::cout << "Write the name of your Trust account: " << std::endl;
			std::getline(std::cin, accountName);
			accountBalance = RequestBalanceFromUser();
			account = std::make_unique<TrustAccount>(accountName, accountBalance);
			break;
		default:
			numberChosen = 0;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid input. Please write one of the given numbers." << std::endl;
			break;
		}
	}
	return account;
}
