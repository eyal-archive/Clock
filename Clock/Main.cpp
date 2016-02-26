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
	Clock digital(timer, digitalDisplay);

	while (true) {
		timer.Thick();
	}

	std::cin.get();
}