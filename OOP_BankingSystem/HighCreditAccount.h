/*
* 클래스 이름 : HighCreditAccount.h
* 업데이트 정보 : 0.7
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"
#include "AccountException.h"

class HighCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	// HighCreditAccount(int ID, int money, char* name, int rate, int special) :
	HighCreditAccount(int ID, int money, String name, int rate, int special) :
		NormalAccount(ID, money, name, rate), specialRate(special) { }
	virtual void Deposit(int money) {
		if (money < 0)
			throw MinusException(money);

		NormalAccount::Deposit(money);						 // 원금 추가
		Account::Deposit(money * (specialRate / 100.0));	 // 이자 추가
	}
};

#endif // !__HIGHCREDIT_ACCOUNT_H__
