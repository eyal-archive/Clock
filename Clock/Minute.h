#pragma once
#include "TimeValue.h"

class Minute final : public TimeValue {
public:
	Minute();
	explicit Minute(tm*);
	~Minute();

	int GetValue() override;
};