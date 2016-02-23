#pragma once
#include "ClockDisplay.h"
#include "TimeFormatter.h"
#include "Console.h"

class DigitalClockConsoleDisplay final : public ClockDisplay {
public:
	DigitalClockConsoleDisplay(TimeFormatter&, Console&);
	void Draw(int hour, int min, int sec) noexcept override;
private:
	Console& _console;
	TimeFormatter& _timeFormatter;
};