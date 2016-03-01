#pragma once
#include "TimeValue.h"

class Minute final : public TimeValue {
public:
	Minute();
	Minute(tm* time);
	~Minute();

	int GetValue() override;
};