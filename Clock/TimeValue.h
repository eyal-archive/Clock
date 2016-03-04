#pragma once
#include <ctime>
#include <string>

class TimeValue {
public:
	int GetValue() const;
	std::string ToString() const;
	std::string ToString(bool) const;
protected:
	TimeValue();
	TimeValue(int* const);
	virtual ~TimeValue();
private:
	const int* _value;
};