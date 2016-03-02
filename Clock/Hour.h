#pragma once
#include "TimeValue.h"

class Hour final : public TimeValue {
public:
	Hour();
	explicit Hour(tm*);
	~Hour();

	int GetValue() override;
};