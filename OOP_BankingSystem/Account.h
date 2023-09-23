/*
* 파일이름 : Account.h
* 업데이트 정보 : 0.8
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accID;	   // 계좌번호
	int balance;   // 잔액
	String cusName; // char* cusName; // 고객이름

public:
	Account(int ID, int money, String name);
	/*Account(int ID, int money, char* name);
	Account(const Account& ref);
	Account& operator = (const Account& ref);*/

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	// ~Account();
};
#endif