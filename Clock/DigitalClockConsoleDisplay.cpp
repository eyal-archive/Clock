#include "DigitalClockConsoleDisplay.h"

DigitalClockConsoleDisplay::DigitalClockConsoleDisplay(TimeFormatter& timeFormatter, Console& console)
		: _timeFormatter(timeFormatter), _console(console)
	{
		_console.HideCursor();
	}

void DigitalClockConsoleDisplay::Draw(int hour, int min, int sec) noexcept {
	_console.Clear();
	_console.Write(_timeFormatter.Format(hour, min, sec));
}
