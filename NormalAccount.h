/*
* File Name: NormalAccount.h
* Banking System
*/

#ifndef __NORMAL_ACCOUNT_H_
#define __NORMAL_ACCOUNT_H_

#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account {
	int interRate; //interest %unit
public:
	NormalAccount(int ID, int money, String name, int rate):Account(ID, money, name),interRate(rate){}
	virtual void Deposit(int money) {
		if (money < 0)
			throw MinusException(money);
		Account::Deposit(money);   //Add principal
		Account::Deposit(money*(interRate / 100.0));   //Add interest
	}
};


#endif
