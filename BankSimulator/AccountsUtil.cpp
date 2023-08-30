#include "AccountsUtil.h"
#include <sstream>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

void DepositToAccountsInVector(std::vector<Account*> &accounts, double amountToDeposit) // Raw pointers
{
	std::cout << std::endl << "DEPOSIT RESULTS:" << std::endl;
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

void DepositToAccountsInVector(std::vector<std::unique_ptr<Account>> &accounts, double amountToDeposit) // Smart pointers
{
	std::cout << std::endl <<"DEPOSIT RESULTS:" << std::endl;
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

void WithdrawFromAccountsInVector(std::vector<Account*>& accounts, double amountToWithdraw)  // Raw pointers
{
	std::cout << std::endl << "WITHDRAWING RESULTS:" << std::endl;
	for (Account* acc : accounts)
	{
		if (acc->Withdraw(amountToWithdraw))
		{
			std::cout << "Successful Withdraw: " << acc->Print() << std::endl;
		}
	}
}

void WithdrawFromAccountsInVector(std::vector<std::unique_ptr<Account>>& accounts, double amountToWithdraw) // Smart pointers
{
	std::cout <<std::endl << "WITHDRAWING RESULTS:" << std::endl;
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
	std::cout << std::endl << std::setw(51)  << "------------------------------------------" << std::endl;
	if (accounts.size() == 0) {
		std::cout << std::setw(48) << "THERE ARE NO ACCOUNTS IN YOUR SYSTEM" << std::endl;
		std::cout << std::setw(55) << "You can create accounts from the console menu." << std::endl;
	}
	for (std::unique_ptr<Account> &acc : accounts)
	{
		std::cout  << std::setw(10) << "|" << ++i << ". " << acc->Print() << std::endl;
	}
	std::cout << std::setw(51) << "------------------------------------------" << std::endl;

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
		std::cout << "'Accounts' file doesn't exist." << std::endl;
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
				int withdrawCounter;
				lineStream >> accBalance >> accIntRate >>withdrawCounter;
				accounts.push_back(std::make_unique<TrustAccount>(accName, accBalance, accIntRate, withdrawCounter));
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

void DepositToAccount(std::unique_ptr<Account>& accountForDeposit)
{
	std::cout << "You are about to deposit money to account [" << accountForDeposit->GetName()<<"].";
	accountForDeposit->Deposit(RequestBalanceFromUser());
}

void WithdrawFromAccount(std::unique_ptr<Account>& accountForWihthdraw)
{
	std::cout << "You are about to withdraw money from account [" << accountForWihthdraw->GetName() << "].";
	accountForWihthdraw->Withdraw(RequestBalanceFromUser());
}

double RequestBalanceFromUser()
{
	double balanceInput{ -1 };
	while (balanceInput == -1)
	{
		try
		{
			std::cout << " Please input your number:";
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
			std::cout<<std::endl << "Invalid input: "<< ex.what() << std::endl;
		}
	}
	return balanceInput;
}

std::unique_ptr<Account>& GetAccountFromVector(std::vector<std::unique_ptr<Account>>& vec)
{
	int choice {0};
	std::cout << "Write which account number you would like ot modify: " << std::endl;
	Display(vec);
	std::cout << "Choose between 1 and " << vec.size() << " : ";
	while (choice == 0) 
	{
		if (std::cin >> choice)
		{
			if (choice > 0 && choice <= vec.size())
			{
				break;
			}
			else
			{ 
				choice = 0;
			}
		}
		std::cout << "Please, write a valid account number."<<std::endl;
		std::cout << "Choose between 1 and " << vec.size() << " : ";
	}

	return vec.at(choice-1);
}


std::unique_ptr<Account> CreateAccount()
{
	std::unique_ptr<Account> account;

	std::cout << std::endl << std::endl << "Write the corresponding number of the type of account you would like to create:" << std::endl;
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
			std::cout << std::endl << "Write the name of your new Savings account: ";
			std::getline(std::cin, accountName);
			std::cout << std::endl << "Write the starting balance of your Savings account.";
			accountBalance = RequestBalanceFromUser();
			account = std::make_unique<SavingsAccount>(accountName, accountBalance);
			break;
		case 2:
			std::cout << std::endl << "Write the name of your new Checking account: ";
			std::getline(std::cin, accountName);
			std::cout << std::endl << "Write the starting balance of your Checking account.";
			accountBalance = RequestBalanceFromUser();
			account = std::make_unique<CheckingAccount>(accountName, accountBalance);
			break;
		case 3:
			std::cout << std::endl << "Write the name of your new Trust account: ";
			std::getline(std::cin, accountName);
			std::cout << std::endl << "Write the starting balance of your Trust account.";
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