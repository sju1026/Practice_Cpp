#include <iostream>
#include <cstring>
#include "Car.h"
#pragma warning(disable:4996)
using namespace std;

void Car::InitMembers(const char * ID, int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::Accel() {
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;
	if ((curSpeed<CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}