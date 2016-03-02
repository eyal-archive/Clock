#include <random>
#include "Event.h"

Event::Callback::Callback(std::function<void(Event*)> func)
	: _func(func) {
}

Event::Callback::~Callback() {
}

void Event::Callback::operator()(Event* e) {
	_func(e);
}

Event::Callback Event::Attach(std::function<void(Event*)> func) {
	Callback callback = Callback(func);
	_callbacks.push_back(callback);
	return callback;
}

void Event::Detach(Callback callback) {
	// todo: NYI
}

void Event::Notify() {
	for (auto callback : _callbacks) {
		callback(this);
	}
}