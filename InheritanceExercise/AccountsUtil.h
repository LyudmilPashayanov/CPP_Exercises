#pragma once
#include <vector>
#include "Account.h"

void Deposit(std::vector<Account> &accounts, double amountToDeposit);
void Withdraw(std::vector<Account> &accounts, double amountToWithdraw);
void Display(std::vector<Account> &accounts);

