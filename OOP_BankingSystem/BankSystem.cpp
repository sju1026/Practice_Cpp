#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

#pragma region Condition
/*
* Banking System Ver 0.1 *
* 작성자 : 서재웅 *
* 내용 : OOP 단계별 프로젝트와 기본 틀 구성
*/

/*
* Banking System Ver 0.2 *
* 내용 : Account 클래스 정의, 객체 포인터 배열 적용
*/

/*
* Banking System Ver 0.3 *
* 내용 : Account 클래스에 추가된 복사 생성자
*/

/*
* Banking System Ver 0.5 *
* 내용 : AccountHandler라는 이름의 컨트롤 클래스 정의
*/
#pragma endregion

#pragma region Function Identity
void ShowMenu(void);		// 메뉴 출력
void MakeAccount(void);		// 계좌개설을 위한 함수
void DepositMoney(void);	// 입금
void WithDrawMoney(void);	// 출금
void ShowAllAccInfo(void);	// 잔액조회
#pragma endregion


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
* 클래스 이름 : Account
* 클래스 유형 : Entity 클래스
*/

class Account {
private:
	int accID;	   // 계좌번호
	int balance;   // 잔액
	char* cusName; // 고객이름

public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);

	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int ID, int money, char* name) :accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) :accID(ref.accID), balance(ref.balance) 
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::Withdraw(int money) { // 출금액 반환, 부족 시 0 반환
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const{
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}

Account::~Account() {
	delete[]cusName;
}

/*
* 클래스 이름 : AccountHandler
* 클래스 유형 : 컨트롤(Control) 클래스
*/

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
};

void AccountHandler::ShowMenu (void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void AccountHandler::WithDrawMoney(void)
{
	int money;
	int id;
	cout << "[출  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

AccountHandler::AccountHandler() : accNum(0) { }

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}

/*
*  컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
*/
int main(){
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithDrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}
