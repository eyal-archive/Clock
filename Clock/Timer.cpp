#include "Timer.h"

Timer::Timer()
	: _onThick(std::make_unique<Event>()) {
}

void Timer::Attach(std::function<void(Event*)> func) {
	_onThick->Attach(func);
}

Hour Timer::GetHour() const {
	return _hour;
}

Minute Timer::GetMinute() const {
	return _minute;
}

Second Timer::GetSecond() const {
	return _second;
}

void Timer::Tick() {
	auto currentTime = time(0);

#if (_MSC_VER >= 1400) 
#pragma warning(disable: 4996)
#endif
	auto* localTime = localtime(&currentTime);
#if (_MSC_VER >= 1400) 
#pragma warning(default: 4996)
#endif

	_second = Second(localTime);

	if (_second.GetValue() != _oldSec)
	{
		_hour = Hour(localTime);
		_minute = Minute(localTime);
		_oldSec = _second.GetValue();

		_onThick->Notify();
	}
}

