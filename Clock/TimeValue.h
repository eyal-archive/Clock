#pragma once
#include <ctime>
#include <string>

class TimeValue {
public:
	virtual int GetValue() = 0;
	std::string ToString();
	std::string ToString(bool);
protected:
	TimeValue();
	virtual ~TimeValue();

	void SetTimePointer(int*);
	int* GetTimePointer();
private:
	int* _value;
};