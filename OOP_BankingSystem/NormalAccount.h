/*
* 파일이름 : NormalAccount.h
* 업데이트 정보 : 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
	int interRate;
public:
	NormalAccount(int ID, int money, char* name, int rate) :
		Account(ID, money, name), interRate(rate) { }
	virtual void Deposit(int money) {
		Account::Deposit(money);						 // 원금 추가
		Account::Deposit(money * (interRate / 100.0));	 // 이자 추가
	}
};

#endif // !__NORMAL_ACCOUNT_H__
