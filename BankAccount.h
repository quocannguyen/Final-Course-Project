#pragma once

class BankAccount {
protected:
	float balance;
	float annualInterestRate;
	float serviceCharges;		// Monthly
	int numberOfDeposits;		// Monthly
	int numberOfWithdrawals;	// Monthly

	BankAccount(float balance, float interestRate);
	virtual void deposit(float amount);
	virtual void withdraw(float amount);
	virtual void calculateInterest();
	virtual void monthlyProc();
	virtual void display();
};