/*
* 파일이름 : AccountException.h
* 업데이트 정보 : 0.8
*/

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class MinusException {
private:
	int exval; // 예외의 원인이 되는금액
public:
	MinusException(int val) : exval(val) { }
	void ShowExceptionInfo(void) const {
		cout << "입(출)금액 " << exval << "은 유효하지 않습니다!" << endl;
	}
};

class InsuffException {
private:
	int balance;
	int reqval;
public:
	InsuffException(int val, int req)
		: balance(val), reqval(req) { }

	void ShowExceptionInfo() const {
		cout << "잔액에서 " << reqval-balance << "가(이) 부족합니다!" << endl;
	}
};

#endif // !__ACCOUNT_EXCEPTION_H__
