#include "Hour.h"

Hour::Hour() : TimeValue() {
}

Hour::Hour(tm* time)
	: TimeValue(&time->tm_hour) {
}

Hour::~Hour() {
}