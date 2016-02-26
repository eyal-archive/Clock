#include "Console.h"
#include "Timer.h"
#include "Clock.h"
#include "DigitalClockTimeFormatter.h"
#include "DigitalClockConsoleDisplay.h"

int main() {
	Console console;

	DigitalClockTimeFormatter formatter;
	DigitalClockConsoleDisplay digitalDisplay(formatter, console);
	
	Timer timer;
	Clock digitalClock(timer, digitalDisplay);

	digitalClock.Start();

	//std::cin.get();
}