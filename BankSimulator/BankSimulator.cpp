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
        std::cout << "3. Deposit to account of your choice." << std::endl;
        std::cout << "4. Withdraw from an account of your choice." << std::endl;
        std::cout << "5. Deposit to all accounts." << std::endl;
        std::cout << "6. Withdraw from all accounts." << std::endl;
        std::cout << "7. Delete all accounts." << std::endl;
        std::cout << "8. Save your account changes." << std::endl;
        std::cout << "9. Exit" << std::endl;

        std::cout << "Enter your choice (1-9): ";
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
            break;
        case 3:
            DepositToAccount(GetAccountFromVector(vec));
            break;
        case 4:
            try
            {
                WithdrawFromAccount(GetAccountFromVector(vec));
            }
            catch (const InsufficientFundsException& ex)
            {
                std::cerr << ex.what() << std::endl;
            }
            break;
        case 5:
            std::cout << "You are about to Deposit money to all accounts. ";
            DepositToAccountsInVector(vec, RequestBalanceFromUser());
            break;
        case 6:
            try
            {
                std::cout << "You are about to Withdraw money from all accounts. ";
                WithdrawFromAccountsInVector(vec, RequestBalanceFromUser());
            }
            catch (const InsufficientFundsException& ex)
            {
                std::cerr << ex.what() << std::endl;
            }
            break;
        case 7:
            vec.clear();
            break;
        case 8:
            WriteFileWithAccounts(vec);
            break;
        case 9:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
        }
    }
}