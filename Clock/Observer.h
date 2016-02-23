#pragma once
#include "Subject.h"

class Subject;

class Observer {
public:
	virtual ~Observer();
	virtual void OnUpdate(Subject* subject) = 0;
protected:
	Observer();
};
