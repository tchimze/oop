/*
Attributes: Account Number, Balance, Account Holder
Methods:
	Deposite: Adds an amount to the balance
	Widthdraw: Subtract an ammount from the balance, if sufficient funds are available
	CheckBalance: Returns the cureent balance 
 */

#include <stdio.h>
#include <string.h>

struct BankAccount {
	char accountNumber[20];
	double balance;
	char accountHolder[100];
};

void Deposite(struct BankAccount* account, double amount) {
	account->balance += amount;
}

void Withdraw(struct BankAccount* account, double amount) {
	if (amount <= account->balance) {
		account->balance -= amount;
	} else {
		printf("Insufficient funds.\n");
	}
}

double CheckBalance(const struct BankAccount* account) {
 	return account->balance;
}

int main() {
	struct BankAccount account1 = {"123456789", 100.0, "John Doe"};
	Deposite(&account1, 500.0);
	Withdraw(&account1, 200.0);
	printf("Account balance: $%.2f\n", CheckBalance(&account1));

	return 0;
}
