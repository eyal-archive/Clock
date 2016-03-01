#pragma once
#include "TimeValue.h"

class Hour final : public TimeValue {
public:
	Hour();
	Hour(tm*);
	~Hour();

	int GetValue() override;
};