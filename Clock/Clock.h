#pragma once
#include "Timer.h"
#include "ClockDisplay.h"

class Clock final {
public:
	Clock(Timer&, ClockDisplay&);
	void Start();
	void Stop();
private:
	Timer& _timer;
	ClockDisplay& _display;
};