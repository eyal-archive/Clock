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
	auto currentTime = time(0);

#if (_MSC_VER >= 1400) 
#pragma warning(disable: 4996)
#endif
	auto *localTime = localtime(&currentTime);
#if (_MSC_VER >= 1400) 
#pragma warning(default: 4996)
#endif

	_second = localTime->tm_sec;

	if (_second != _oldSec)
	{
		_hour = localTime->tm_hour;
		_minute = localTime->tm_min;
		_oldSec = _second;

		_onThick->Notify();
	}
}

