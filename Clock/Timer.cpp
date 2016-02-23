#include "Timer.h"

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

		Notify();
	}
}

