#pragma once
#include <string>

class TimeFormatter {
public:
	virtual std::string Format(int, int, int) noexcept = 0;
};

