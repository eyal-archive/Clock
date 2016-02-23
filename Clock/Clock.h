#pragma once
#include "Timer.h"
#include "ClockDisplay.h"
#include "Subject.h"

class Clock final : public Observer {
public:
	Clock(Timer& timer, ClockDisplay& display);
	~Clock();
	void OnUpdate(Subject* timer) override;
private:
	Timer& _timer;
	ClockDisplay& _display;
};
