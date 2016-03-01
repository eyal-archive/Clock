#include "TimeValue.h"

TimeValue::TimeValue() {
	_value = nullptr;
}

TimeValue::~TimeValue() {
}

void TimeValue::SetTimePointer(int* value) {
	_value = value;
}

int* TimeValue::GetTimePointer() {
	return _value;
}

std::string TimeValue::ToString() {
	return std::to_string(GetValue());
}

std::string TimeValue::ToString(bool addZeroBelowTen) {
	int value = GetValue();
	std::string str_value = std::to_string(value);

	return addZeroBelowTen && value <= 9 ? "0" + str_value : str_value;
}