#pragma once
#include "Timer.h"
#include "ClockDisplay.h"

class Clock final {
public:
	Clock(Timer& timer, ClockDisplay& display);
	~Clock();
private:
	void Update();

	Timer& _timer;
	ClockDisplay& _display;
};