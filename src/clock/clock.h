#pragma once
#include "timer.h"
#include "clock_display.h"

class Clock final {
public:
    Clock(Timer&, ClockDisplay&);
    void Start();
    void Stop();
private:
    Timer& _timer;
    ClockDisplay& _display;
};
