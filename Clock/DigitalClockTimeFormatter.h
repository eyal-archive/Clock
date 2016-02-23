#pragma once
#include "TimeFormatter.h"

class DigitalClockTimeFormatter final : public TimeFormatter {
public:
	std::string Format(int hour, int min, int sec) noexcept override;
};