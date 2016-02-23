#pragma once
#include <set>
#include "Observer.h"

class Observer;

class Subject {
public:
	void Attach(Observer*);
	void Detach(Observer*);
	void Notify();
protected:
	Subject();
	virtual ~Subject();
private:
	std::set<Observer*> _observers;
};