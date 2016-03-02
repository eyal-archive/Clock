#pragma once
#include "TimeValue.h"

class Second final : public TimeValue {
public:
	Second();
	explicit Second(tm*);
	~Second();

	int GetValue() override;
};