#pragma once
#include <ctime>
#include "Event.h"
#include "Second.h"
#include "Minute.h"
#include "Hour.h"

class Timer final {
public:
	Timer();
	~Timer();

	void Attach(std::function<void(Event*)> func);
	void Detach(std::function<void(Event*)> func);

	Hour GetHour();
	Minute GetMinute();
	Second GetSecond();

	void Thick();
private:
	Event* _onThick;

	Hour _hour;
	Minute _minute;
	Second _second;

	int _oldSec = -1;
};