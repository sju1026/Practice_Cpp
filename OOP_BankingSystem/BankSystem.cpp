#include <iostream>
#include <cstring>

using namespace std;

#pragma region Condition
/*
* Banking System Ver 0.1 *
* 작성자 : 서재웅 *
* 내용 : OOP 단계별 프로젝트와 기본 틀 구성
*/

/*
* Banking System Ver 0.2 *
* 작성자 : 서재웅 *
* 내용 : Account 클래스 정의, 객체 포인터 배열 적용
*/
#pragma endregion

#pragma region Value
const int NAME_LEN = 20;
#pragma endregion

#pragma region Function
void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithDrawMoney(void);
void ShowAllAccInfo(void);
#pragma endregion

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int accID;	   // 계좌번호
	int balance;   // 잔액
	char* cusName; // 고객이름

public:
	Account(int ID, int money, char* name) :accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
};

typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum = 0;

int main(){
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void WithDrawMoney(void)
{
	int money;
	int id;
	cout << "[출  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이 름: " << accArr[i].cusName << endl;
		cout << "잔 액: " << accArr[i].balance << endl;
	}
}
