#pragma once
#include "time_value.h"

class Minute final : public TimeValue {
public:
	Minute();
	explicit Minute(tm*);
};