/*
* File Name: Account.h
* Banking System
*/

#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

#include "String.h"

class Account {
	int accID;
	int balance;
	String cusName;
public:
	Account(int ID, int money, String name);
	int GetAccID() const;
	virtual void Deposit(int money);
	int withdraw(int money);
	void ShowAccInfo() const;
};


#endif