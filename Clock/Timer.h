#pragma once
#include <time.h>
#include "Subject.h"

class Timer : public Subject {
public:
	int GetHour();
	int GetMinute();
	int GetSecond();

	void Thick();
private:
	int _hour = 0;
	int _minute = 0;
	int _second = 0;

	int _oldSec = -1;
};