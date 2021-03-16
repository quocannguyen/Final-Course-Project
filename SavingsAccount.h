// Preprocessor directive
#pragma once
#include "BankAccount.h" // Class BankAccount

class SavingsAccount : public BankAccount {
	bool status;				// To represent an active or inactive account
	float feePerWithdrawal = 1;

	void setStatus();
public:
	SavingsAccount(float balance, float interestRate);
	void deposit(float amount);
	void withdraw(float amount);
	void monthlyProc();
	void display();
};