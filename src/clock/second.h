#pragma once
#include "time_value.h"

class Second final : public TimeValue {
public:
	Second();
	explicit Second(tm*);
};