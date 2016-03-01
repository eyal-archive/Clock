#pragma once
#include "TimeValue.h"

class Second final : public TimeValue {
public:
	Second();
	Second(tm* time);
	~Second();

	int GetValue() override;
};