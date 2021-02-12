// Preprocessor directive
#include "BankAccount.h"
#include <iostream>			// cout
#include <iomanip>			// setprecision

BankAccount::BankAccount(float balance, float interestRate) {
	this->balance = balance;
	annualInterestRate = interestRate;
	numberOfDeposits = 0;
	numberOfWithdrawals = 0;
	serviceCharges = 0;
}

void BankAccount::deposit(float amount) {
	balance += amount;
	numberOfDeposits++;
}

void BankAccount::withdraw(float amount) {
	balance -= amount;
	numberOfWithdrawals++;
}

void BankAccount::calculateInterest() {
	float monthlyInterestRate = annualInterestRate / 12;
	float monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

void BankAccount::monthlyProc() {
	balance -= serviceCharges;
	calculateInterest();
	numberOfDeposits = 0;
	numberOfWithdrawals = 0;
	serviceCharges = 0;
}

void BankAccount::display() {
	std::cout << "Withdrawals: "		<< "\t\t" << numberOfWithdrawals	<< '\n';
	std::cout << "Deposits: "			<< "\t\t" << numberOfDeposits		<< '\n';
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Service Charges: "	<< '\t' << serviceCharges			<< '\n';
	std::cout << "Ending Balance: "		<< '\t' << balance					<< '\n';	// Do we need to monthlyProc() before cout << balance ??????????
	std::cout																<< '\n';	// What does Ending Balance mean ???????????????????????????????
}