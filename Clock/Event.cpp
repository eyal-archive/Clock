#include "Event.h"

void Event::Attach(std::function<void(Event*)> func) {
	_funcs.push_back(func);
}

void Event::Detach(std::function<void(Event*)> func) {
	// todo: NYI
}

void Event::Notify() {
	for (auto item : _funcs) {
		item(this);
	}
}