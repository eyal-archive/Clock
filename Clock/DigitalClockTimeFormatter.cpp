#include "DigitalClockTimeFormatter.h"

std::string DigitalClockTimeFormatter::Format(int hour, int min, int sec) noexcept {
	std::string h = std::to_string(hour);
	std::string m = std::to_string(min);
	std::string s = std::to_string(sec);

	m = min <= 9 ? "0" + m : m;
	s = sec <= 9 ? "0" + s : s;

	return h + ":" + m + ":" + s;
}