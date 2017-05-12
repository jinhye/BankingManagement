/*
* File Name: AccountHandler.cpp
* Banking System
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu() const {
	cout << "------ Menu ------" << endl;
	cout << "1. Account open" << endl;
	cout << "2. Deposit" << endl;
	cout << "3.Withdraw" << endl;
	cout << "4. Display all accounts information" << endl;
	cout << "5. Program ends" << endl;
}

void AccountHandler::MakeAccount() {
	int sel;
	cout << "[Select an account]" << endl;
	cout << "1. Checking account" << endl;
	cout << "2. Savings account" << endl;
	cout << "Selection: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount() {
	int id;
	String name;
	int balance;
	int interRate;

	cout << "[Checking accoung open]" << endl;
	cout << "AccountID: ";
	cin >> id;
	cout << "Name: ";
	cin >> name;
	cout << "Amount: ";
	cin >> balance;
	cout << "Interest: ";
	cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	String name;
	int balance;
	int interRate;
	int creditLevel;

	cout << "[Savings accoung open]" << endl;
	cout << "AccountID: ";
	cin >> id;
	cout << "Name: ";
	cin >> name;
	cout << "Amount: ";
	cin >> balance;
	cout << "Interest: ";
	cin >> interRate;
	cout << "Credit Level(1toA, 2toB, 3toC): ";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel) {
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney() {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;

	while (true) {
		cout << "Deposit Amount: ";
		cin >> money;
		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					accArr[i]->Deposit(money);
					cout << "Deposit succeeded" << endl << endl;
					return;
				}
			}
			cout << "Invalid ID" << endl << endl;
			return;
		}
		catch (MinusException& expt) {
			expt.ShowExceptionInfo();
			cout << "Re-enter deposit amount" << endl;
		}
	}
}

void AccountHandler::WithdrawMoney() {
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID: ";
	cin >> id;

	while (true) {
		cout << "Withdraw Amount: ";
		cin >> money;
		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					accArr[i]->withdraw(money);
					cout << "Withdraw succeeded" << endl << endl;
					return;
				}
			}
			cout << "Invalid ID" << endl << endl;
			return;
		}
		catch (MinusException& expt) {
			expt.ShowExceptionInfo();
			cout << "Re-enter deposit amount" << endl;
		}
		catch (InsuffException& expt) {
			expt.ShowExceptionInfo();
			cout << "Re-enter withdraw amount" << endl;
		}
	}
}

AccountHandler::AccountHandler():accNum(0){}

void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}