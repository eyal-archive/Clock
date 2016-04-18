#include "time_value.h"

TimeValue::TimeValue()
	: _value(nullptr) {
}

TimeValue::TimeValue(int* const value)
	: _value(value){
}

TimeValue::~TimeValue() {
}

int TimeValue::GetValue() const {
	return *_value;
}

std::string TimeValue::ToString() const {
	return std::to_string(GetValue());
}

std::string TimeValue::ToString(bool addZeroBelowTen) const {
	int value = GetValue();
	std::string str_value = std::to_string(value);

	return addZeroBelowTen && value <= 9 ? "0" + str_value : str_value;
}