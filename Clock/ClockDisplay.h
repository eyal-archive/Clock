#pragma once
#include "Second.h"
#include "Minute.h"
#include "Hour.h"

class ClockDisplay {
public:
	virtual void Draw(Hour, Minute, Second) const noexcept = 0;
};
