#include "DigitalClockConsoleDisplay.h"

DigitalClockConsoleDisplay::DigitalClockConsoleDisplay(Console& console)
	: _console(console) {
	_console.HideCursor();
}

void DigitalClockConsoleDisplay::Draw(Hour hour, Minute min, Second sec) const noexcept {
	_console.Clear();
	_console.Write(hour.ToString() + ":" + min.ToString(true) + ":" + sec.ToString(true));
}
