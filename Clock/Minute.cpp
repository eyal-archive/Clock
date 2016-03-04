#include "Minute.h"

Minute::Minute() : TimeValue() {
}

Minute::Minute(tm* time) 
	: TimeValue(&time->tm_min) {
}

Minute::~Minute() {
}