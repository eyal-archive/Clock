#include "Second.h"

Second::Second() : TimeValue() {
}

Second::Second(tm* time) {
	SetTimePointer(&time->tm_sec);
}

Second::~Second() {
}

int Second::GetValue() {
	return *GetTimePointer();
}