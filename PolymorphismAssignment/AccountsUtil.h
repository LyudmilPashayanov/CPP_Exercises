#pragma once
#include <vector>
#include <fstream>
#include "Account.h"

void Deposit(std::vector<Account*>& accounts, double amountToDeposit); // Raw pointers
void Deposit(std::vector<std::unique_ptr<Account>>& accounts, double amountToDeposit); // Smart pointers
void Withdraw(std::vector<Account*>& accounts, double amountToWithdraw); // Raw pointers
void Withdraw(std::vector<std::unique_ptr<Account>>& accounts, double amountToWithdraw); // Smart pointers
void Display(std::vector<std::unique_ptr<Account>>& accounts);
void WriteFileWithAccounts(std::vector<std::unique_ptr<Account>>& vec);
std::vector<std::unique_ptr<Account>> ReadFileWithAccounts();
std::unique_ptr<Account> CreateAccount();
double RequestBalanceFromUser();

