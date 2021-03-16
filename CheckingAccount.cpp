// Preprocessor directive
#include "CheckingAccount.h"	// Class CheckingAccount
#include <iostream>				// cout

float CheckingAccount::balanceBelow0Fee = 15;
float CheckingAccount::baseMonthlyFee = 5;
float CheckingAccount::feePerWithdrawal = 0.1;

CheckingAccount::CheckingAccount(float balance, float interestRate) : BankAccount(balance, interestRate) {}

void CheckingAccount::deposit(float amount) { BankAccount::deposit(amount); }

void CheckingAccount::withdraw(float amount) {
	if (balance - amount < 0) {
		balance -= balanceBelow0Fee;
		std::cout << "The withdrawal would cause the balance to go below $0.\n";
		std::cout << "A service charge of " << balanceBelow0Fee << " was taken from the account.\n";
		std::cout << "The withdrawal was not made.\n";
		std::cout << "Balance: " << balance	<< '\n';
	}
	else BankAccount::withdraw(amount);	// If balance - amount == 0: withdraw()
										// Is this true ????????????????????????????????????????????????????????????????????????????????????????????????
}

void CheckingAccount::monthlyProc() {
	serviceCharges += baseMonthlyFee + feePerWithdrawal * numberOfWithdrawals;
}

void CheckingAccount::display() {
	std::cout << "CHECKING ACCOUNT MONTHLY STATISTICS:\n";
	BankAccount::display();
}