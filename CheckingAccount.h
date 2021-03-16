// Preprocessor directive
#pragma once
#include "BankAccount.h" // Class BankAccount

class CheckingAccount : public BankAccount {
	static float balanceBelow0Fee;	// Fee when the balance goes below $0
	static float baseMonthlyFee;
	static float feePerWithdrawal;

public:
	CheckingAccount(float balance, float interestRate);
	void deposit(float amount);
	void withdraw(float amount);
	void monthlyProc();
	void display();
};