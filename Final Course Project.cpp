// Name: Quoc An Nguyen
// Date: 23rd April, 2021
//
// Program statement: ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

// Preprocessor directive
#include <iostream>				// cout, cin
#include "SavingsAccount.h"		// Class SavingsAccount
#include "CheckingAccount.h"	// Class CheckingAccount

// Function Prototype
bool isPositive(float amount);

int main()
{
	float savingsBaseBalance = 0;	//
	float checkingBaseBalance = 0;	//
	float savingsInterest = 0;		//
	float checkingInterest = 0;		//

	SavingsAccount savings(savingsBaseBalance, savingsInterest);
	CheckingAccount checking(checkingBaseBalance, checkingInterest);
	int choice;
	float amount;

	while (true) {
		std::cout << "******** BANK ACCOUNT MENU ********\n";
		std::cout << "1. Savings Account Deposit\n";
		std::cout << "2. Checking Account Deposit\n";
		std::cout << "3. Savings Account Withdrawal\n";
		std::cout << "4. Checking Account Withdrawal\n";
		std::cout << "5. Update and Display Account Statistics\n";
		std::cout << "6. Exit\n";
		std::cout << "Your choice, please (1 - 6): ";
		std::cin >> choice;
		std::cout << '\n';
		
		if (std::cin.fail()) {	// If input is not a number
			std::cin.clear();	// Sets a new value for the stream's internal error state flags [...] all error flags are cleared.
			std::cin.ignore();	// Extracts characters from the input sequence and discards them.
			continue;			// Must clear() before ignore(). I don't know why ???
		}
		if (choice == 6) break;
		switch (choice) {
		case 1:
			std::cout << "1. Enter amount to deposit to Savings Account: ";
			std::cin >> amount;
			if (isPositive(amount)) savings.deposit(amount);
			break;
		case 2:
			std::cout << "2. Enter amount to deposit to Checking Account: ";
			std::cin >> amount;
			if (isPositive(amount)) checking.deposit(amount);
			break;
		case 3:
			std::cout << "3. Enter amount to deposit to Savings Account: ";
			std::cin >> amount;
			if (isPositive(amount)) savings.withdraw(amount);
			break;
		case 4:
			std::cout << "4. Enter amount to deposit to Checking Account: ";
			std::cin >> amount;
			if (isPositive(amount)) checking.withdraw(amount);
			break;
		case 5:
			savings.display();
			//system("pause");	// Press a key to continue . . .
								// Windows-specific command
			checking.display();
			break;
		default: break;
		}

		std::cout << '\n';
	}
}

// Function Definition
bool isPositive(float amount) {
	if (amount > 0) return true;
	else {
		std::cout << "Amount is less than or equal to zero. Action did not go through.\n";
		return false;
	}
}