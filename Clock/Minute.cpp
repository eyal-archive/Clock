#include "Minute.h"

Minute::Minute() : TimeValue() {
}

Minute::Minute(tm* time) {
	SetTimePointer(&time->tm_min);
}

Minute::~Minute() {
}

int Minute::GetValue() {
	return *GetTimePointer();
}