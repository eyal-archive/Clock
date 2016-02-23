#include "Observer.h"
#include "Subject.h"

Observer::Observer() {
}

Observer::~Observer() {
}

void Observer::OnUpdate(Subject* subject) {
	subject->Notify();
}

