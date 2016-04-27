#pragma once
#include "time_value.h"

class Hour final : public TimeValue {
public:
    Hour();
    explicit Hour(tm*);
};
