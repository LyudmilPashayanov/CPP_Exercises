#pragma once
#include <vector>
#include <fstream>
#include "Account.h"

void DepositToAccountsInVector(std::vector<Account*>& accounts, double amountToDeposit); // Raw pointers
void DepositToAccountsInVector(std::vector<std::unique_ptr<Account>>& accounts, double amountToDeposit); // Smart pointers
void WithdrawFromAccountsInVector(std::vector<Account*>& accounts, double amountToWithdraw); // Raw pointers
void WithdrawFromAccountsInVector(std::vector<std::unique_ptr<Account>>& accounts, double amountToWithdraw); // Smart pointers
void DepositToAccount(std::unique_ptr<Account>& accountForDeposit);
void WithdrawFromAccount(std::unique_ptr<Account>& accountForWihthdraw);
void Display(std::vector<std::unique_ptr<Account>>& accounts);
void WriteFileWithAccounts(std::vector<std::unique_ptr<Account>>& vec);
std::vector<std::unique_ptr<Account>> ReadFileWithAccounts();
std::unique_ptr<Account> CreateAccount();
double RequestBalanceFromUser();
std::unique_ptr<Account>& GetAccountFromVector(std::vector<std::unique_ptr<Account>>& vec);

