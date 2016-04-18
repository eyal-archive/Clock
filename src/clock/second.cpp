#include "second.h"

Second::Second() : TimeValue() {
}

Second::Second(tm* time)
	: TimeValue(&time->tm_sec) {
}