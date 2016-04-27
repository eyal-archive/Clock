#include "console.h"
#include "timer.h"
#include "clock.h"
#include "digital_clock-console_display.h"

int main()
{
    Console console;

    DigitalClockConsoleDisplay digitalDisplay(console);

    Timer timer;
    Clock digitalClock(timer, digitalDisplay);

    digitalClock.Start();
}
