#include <iostream>
#include "Car.h"

using namespace std;

#pragma region Structure
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car1
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();
};

void Car1::ShowCarState() {
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재 속도: " << curSpeed <<"km/s" << endl;
}

void Accel(Car1& car) {
	if (car.fuelGauge <= 0)
		return;
	else
		car.fuelGauge -= FUEL_STEP;
	if (car.curSpeed+ACC_STEP>=MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}
	car.curSpeed += ACC_STEP;
}

void Break(Car1& car) {
	if (car.curSpeed<BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}
	car.curSpeed -= BRK_STEP;
}

struct Car2
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {
		cout << "소유자ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재 속도: " << curSpeed << "km/s" << endl;
	}

	void Accel() {
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= FUEL_STEP;
		if (curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}
		curSpeed += ACC_STEP;
	}

	void Break() {
		if (curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		curSpeed -= BRK_STEP;
	}
};

namespace CAR_CONST {
	enum {
		ID_LEN1 = 20,
		MAX_SPD1 = 200,
		FUEL_STEP1 = 2,
		ACC_STEP1 = 10,
		BRK_STEP1 =10
	};
}

struct Car3 {
	char gamerID[CAR_CONST::ID_LEN1];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {
		cout << "소유자ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << endl;
	}
	void Accel() {
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= CAR_CONST::FUEL_STEP1;

		if ((fuelGauge+CAR_CONST::ACC_STEP1)>=CAR_CONST::MAX_SPD1)
		{
			curSpeed = CAR_CONST::MAX_SPD1;
			return;
		}
		curSpeed += CAR_CONST::ACC_STEP1;
	}

	void Break() {
		if (curSpeed<CAR_CONST::BRK_STEP1)
		{
			curSpeed = 0;
			return;
		}

		curSpeed -= CAR_CONST::BRK_STEP1;
	}
};
#pragma endregion

#pragma region OOP
class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) 
	: APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money) 
		:myMoney(money), numOfApples(0)
	{
	}

	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult() {
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};
#pragma endregion

int main(void)
{
	/*Car1 run99 = {"run99", 100, 0};
	Accel(run99);
	Accel(run99);
	run99.ShowCarState();
	cout << endl;
	Break(run99);
	run99.ShowCarState();
	cout << endl;

	Car2 run77 = { "run77", 100, 0 };
	run77.Accel();
	run77.Break();
	run77.ShowCarState();
	cout << endl;
	Car3 run88 = { "run88", 100, 0 };
	run88.Accel();
	run88.Break();
	run88.ShowCarState();*/

	/*Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();	
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();*/

	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}

