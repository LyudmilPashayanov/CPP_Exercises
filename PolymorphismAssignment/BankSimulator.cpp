#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "AccountsUtil.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

int main()
{
    std::vector<std::unique_ptr<Account>> vec;
    vec = ReadFileWithAccounts();

    int choice;
    while (true) {
        std::cout << std::endl << std::endl << std::endl <<"Menu:" << std::endl;
        std::cout << "1. Read currently saved accounts." << std::endl;
        std::cout << "2. Create and add an account." << std::endl;
        std::cout << "3. Deposit to all accounts." << std::endl;
        std::cout << "4. Withdraw from all accounts." << std::endl;
        std::cout << "5. Delete all accounts." << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice (1-5): ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            Display(vec);
            break;
        case 2:
            vec.push_back(std::move(CreateAccount()));
            WriteFileWithAccounts(vec);
            break;
        case 3:
            Deposit(vec, RequestBalanceFromUser());
            WriteFileWithAccounts(vec);
            break;
        case 4:
            try
            {
                Withdraw(vec, RequestBalanceFromUser());
                WriteFileWithAccounts(vec);
            }
            catch (const InsufficientFundsException& ex)
            {
                std::cerr << ex.what() << std::endl;
            }
            break;
        case 5:
            vec.clear();
            WriteFileWithAccounts(vec);
            break;
        case 6:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
        }
    }
}