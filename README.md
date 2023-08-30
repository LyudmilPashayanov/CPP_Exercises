# Bank account simulator
## About the project
"Bank Account Simulator" is a C++ Console App project, which was created with the goal showcase my knowledge of the language by demonstrating foundational C++ concepts. "Bank Account Simulator" is a simple application in which you can create different types of accounts and then operate with them from the console.

### Account types:
 - *Savings Account*: Every time you Deposit money to this account, you get a little extra % on top.
 - *Trust Account* Uses the same Deposit as the "Savings Account", but if you Deposit more than 5000$ you receive a bonus of 50$. However, you can withdraw from the account only 3 times per year and you can not withdraw more than 20% of the balance in the account.
 - *Checking Account*: Every time you Withdraw money from this account, a flat fee is applied on top of the withdraw amount.

## Showcasing
 - Inheritance and Polymorphism is used to create the Accounts logic.
 - Use of file stream to Save/Load Accounts from a .txt file.
 - Interface IPersistable is used to mark a class as one which can be printed and saved as a text file.
 - Custom exception handling: When withdrawing money and when giving input to deposit/withdraw money.

## How to run?
You can run the app by:
 - Open the project from any IDE (tested in VS Community) and run it.

## TO-DO (Knowledge not demonstrated, but attained)
- Move and Copy Constructor and Assignment operator overloading.
- Function and Class templates.

## Questions
For further questions about the project please contact me.
