#pragma once
#include <ctime>
#include "Event.h"

class Timer final {
public:
	Timer();
	~Timer();

	void Attach(std::function<void(Event*)> func);
	void Detach(std::function<void(Event*)> func);

	int GetHour();
	int GetMinute();
	int GetSecond();

	void Thick();
private:
	Event* _onThick;

	int _hour = 0;
	int _minute = 0;
	int _second = 0;

	int _oldSec = -1;
};