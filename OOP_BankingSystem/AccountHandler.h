/*
* 클래스 이름 : AccountHandler.h
* 업데이트 정보 : 0.7
*/

#ifndef __ACOUNT_HANDLER_H__
#define __ACOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler {
private:
	Account* accArr[100]; // Account 저장을 위한 배열
	int accNum = 0; // 저장된 Account 수
public:
	AccountHandler();
	void ShowMenu(void) const;		// 메뉴 출력
	void MakeAccount(void);			// 계좌개설을 위한 함수
	void DepositMoney(void);		// 입금
	void WithDrawMoney(void);		// 출금
	void ShowAllAccInfo(void) const;// 잔액조회
	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
};

#endif // !__ACOUNT_HANDLER_H__