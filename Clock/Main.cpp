#include "Console.h"
#include "Timer.h"
#include "Clock.h"
#include "DigitalClockConsoleDisplay.h"

int main() {
	Console console;

	DigitalClockConsoleDisplay digitalDisplay(console);
	
	Timer timer;
	Clock digitalClock(timer, digitalDisplay);

	digitalClock.Start();

	//std::cin.get();
}