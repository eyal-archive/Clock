#pragma once
#include <ctime>
#include <memory>
#include "event.h"
#include "second.h"
#include "minute.h"
#include "hour.h"

class Timer final {
public:
	Timer();

	void Attach(std::function<void(Event*)>);

	Hour GetHour() const;
	Minute GetMinute() const;
	Second GetSecond() const;

	void Tick();
private:
	const std::unique_ptr<Event> _onThick;

	Hour _hour;
	Minute _minute;
	Second _second;

	int _oldSec = -1;
};