#include "Clock.h"
#include "Event.h"

Clock::Clock(Timer& timer, ClockDisplay& display)
	: _timer(timer), _display(display) {
}

Clock::~Clock() {
}

void Clock::Start() {
	_timer.Attach([this](Event*) {
		_display.Draw(_timer.GetHour(), _timer.GetMinute(), _timer.GetSecond());
	});

	while (true) {
		_timer.Tick();
	}
}

void Clock::Stop() {
	// todo: NYI
}