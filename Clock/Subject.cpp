#include "Subject.h"
#include "Observer.h"

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::Attach(Observer* observer) {
	_observers.insert(observer);
}

void Subject::Detach(Observer* observer) {
	_observers.erase(observer);
}

void Subject::Notify() {
	typedef std::set<Observer*>::iterator iterator;

	iterator it;

	for (it = _observers.begin(); it != _observers.end(); ++it) {
		(*it)->OnUpdate(this);
	}
}