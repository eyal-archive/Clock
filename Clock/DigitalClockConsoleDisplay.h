#pragma once
#include "ClockDisplay.h"
#include "Console.h"


class DigitalClockConsoleDisplay final : public ClockDisplay {
public:
	DigitalClockConsoleDisplay(Console&);
	void Draw(Hour, Minute, Second) noexcept override;
private:
	Console& _console;
};