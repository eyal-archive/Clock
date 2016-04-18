#pragma once
#include "second.h"
#include "minute.h"
#include "hour.h"

class ClockDisplay {
public:
	virtual void Draw(Hour, Minute, Second) const = 0;
};
