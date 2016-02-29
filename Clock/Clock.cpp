#include "Clock.h"
#include "Event.h"

Clock::Clock(Timer& timer, ClockDisplay& display)
	: _timer(timer), _display(display) {
}

Clock::~Clock() {
}

void Clock::Start() {
	_timer.Attach([this](Event*) {
		int hour = _timer.GetHour();
		int minute = _timer.GetMinute();
		int second = _timer.GetSecond();

		_display.Draw(hour, minute, second);
	});

	while (true) {
		_timer.Thick();
	}
}

void Clock::Stop() {
	// todo: NYI
}