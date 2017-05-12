/*
* File Name: AccountException.h
* Banking System
*/

#ifndef __ACCOUNT_EXCEPTION_H_
#define __ACCOUNT_EXCEPTION_H_

using namespace std;

class MinusException {
	int exval;
public:
	MinusException(int val): exval(val){}
	void ShowExceptionInfo() const {
		cout << "Amount " << exval << " is not valid" << endl;
	}
};

class InsuffException {
	int balance;
	int reqval;
public:
	InsuffException(int val, int req):balance(val), reqval(req){}
	void ShowExceptionInfo() const {
		cout << reqval - balance << " is not enough " << "from the account" << endl;
	}
};

#endif
