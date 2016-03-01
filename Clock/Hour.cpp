#include "Hour.h"

Hour::Hour() : TimeValue() {
}

Hour::Hour(tm* time) {
	SetTimePointer(&time->tm_hour);
}

Hour::~Hour() {
}

int Hour::GetValue() {
	return *GetTimePointer();
}