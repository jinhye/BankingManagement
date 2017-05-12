/*
* File Name: HighCreditAccount.h
* Banking System
*/

#ifndef __HIGHCREDIT_ACCOUNT_H_
#define __HIGHCREDIT_ACCOUNT_H_

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount :public NormalAccount {
	int specialRate;
public:
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special){}
	virtual void Deposit(int money) {
		if (money < 0)
			throw MinusException(money);
		NormalAccount::Deposit(money);   //Add principal and interest
		Account::Deposit(money*(specialRate / 100.0));   //Add special interest
	}
};



#endif
