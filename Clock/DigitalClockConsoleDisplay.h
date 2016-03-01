#pragma once
#include "ClockDisplay.h"
#include "Console.h"


class DigitalClockConsoleDisplay final : public ClockDisplay {
public:
	DigitalClockConsoleDisplay(Console&);
	void Draw(Hour hour, Minute min, Second sec) noexcept override;
private:
	Console& _console;
};