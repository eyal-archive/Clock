#include "Timer.h"

Timer::Timer()
	: _onThick(new Event()) {
}

Timer::~Timer() {
	delete _onThick;
}

void Timer::Attach(std::function<void(Event*)> func) {
	_onThick->Attach(func);
}

void Timer::Detach(std::function<void(Event*)> func) {
	// todo: NYI
}

int Timer::GetHour() {
	return _hour;
}

int Timer::GetMinute() {
	return _minute;
}

int Timer::GetSecond() {
	return _second;
}

void Timer::Thick() {
	time_t t = time(0);

#if (_MSC_VER >= 1400) 
#pragma warning(disable: 4996)
#endif
	tm *lt = localtime(&t);
#if (_MSC_VER >= 1400) 
#pragma warning(default: 4996)
#endif

	_second = lt->tm_sec;

	if (_second != _oldSec)
	{
		_hour = lt->tm_hour;
		_minute = lt->tm_min;
		_oldSec = _second;

		_onThick->Notify();
	}
}

