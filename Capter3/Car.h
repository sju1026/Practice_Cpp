#ifndef __CAR_H__
#define __CAR_H__
using namespace std;

namespace CAR_CONST {
	enum {
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP=2, ACC_STEP=10, BRK_STEP=10
	};
}

class Car
{
public:
	void InitMembers(const char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
};

inline void Car::ShowCarState() {
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
}

inline void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
#endif // !__CAR_H__

