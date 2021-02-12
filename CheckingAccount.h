#pragma once

// Preprocessor directive
#include "BankAccount.h" // Class BankAccount

class CheckingAccount : public BankAccount {
	float balanceBelow0Fee = 15;	// Fee when the balance goes below $0
	float baseMonthlyFee = 5;
	float feePerWithdrawal = 0.1;

	float monthlyFee() { return 5 + 0.1 * numberOfWithdrawals; }
public:
	CheckingAccount(float balance, float interestRate);
	void deposit(float amount);
	void withdraw(float amount);
	void monthlyProc();
	void display();
};