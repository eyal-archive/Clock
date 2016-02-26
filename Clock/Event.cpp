#include "Event.h"

void Event::Attach(std::function<void(Event*)> func) {
	_funcs.push_back(func);
}

void Event::Detach(std::function<void(Event*)> func) {
	// todo: NYI
}

void Event::Notify() {
	typedef std::list<std::function<void(Event*)>>::iterator iterator;

	iterator it;

	for (it = _funcs.begin(); it != _funcs.end(); ++it) {
		(*it)(this);
	}
}