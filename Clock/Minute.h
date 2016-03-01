#pragma once
#include "TimeValue.h"

class Minute final : public TimeValue {
public:
	Minute();
	Minute(tm*);
	~Minute();

	int GetValue() override;
};