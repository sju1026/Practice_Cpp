/*
* 파일이름 : Account.cpp
* 업데이트 정보 : 0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int ID, int money, String name)
	: accID(ID), balance(money)
{
	/*cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);*/
	cusName = name;
}

/*Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref)
{
	accID = ref.accID;
	balance = ref.balance;

	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	return *this;
}*/

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	if (money < 0)
		throw MinusException(money);

	balance += money;
}

int Account::Withdraw(int money) { // 출금액 반환, 부족 시 0 반환
	if (money < 0)
		throw MinusException(money);

	if (balance < money)
		throw InsuffException(balance, money);

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}

//Account::~Account() {
//	delete[]cusName;
//}