#include "Clock.h"

Clock::Clock(Timer& timer, ClockDisplay& display)
	: _timer(timer), _display(display)
{
	_timer.Attach(this);
}

Clock::~Clock() {
	_timer.Detach(this);
}

void Clock::OnUpdate(Subject* timer) {
	if (timer == &_timer) {
		int hour = _timer.GetHour();
		int minute = _timer.GetMinute();
		int second = _timer.GetSecond();

		_display.Draw(hour, minute, second);
	}
}