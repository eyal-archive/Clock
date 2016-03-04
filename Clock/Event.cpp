#include <random>
#include <algorithm>
#include "Event.h"

Event::Callback::Callback(Event& e, std::function<void(Event*)> func)
	: _id(e._idCounter), _func(func) {
}

Event::Callback::~Callback() {
}

void Event::Callback::operator()(Event* e) {
	_func(e);
}

bool operator==(const Event::Callback& lhs, const Event::Callback& rhs) {
	return lhs.GetID() == rhs.GetID();
}

bool operator!=(const Event::Callback& lhs, const Event::Callback& rhs) {
	return !operator==(lhs, rhs);
}

std::list<Event::Callback>::size_type Event::Callback::GetID() const {
	return _id;
}

Event::Callback Event::Attach(std::function<void(Event*)> func) {
	Callback callback = Callback(*this, func);
	_callbacks.push_back(callback);
	_idCounter++;
	return callback;
}

void Event::Detach(Callback callback) {
	_callbacks.remove(callback);
}

void Event::Notify() {
	for (auto callback : _callbacks) {
		callback(this);
	}
}

std::list<Event::Callback>::size_type Event::Size() {
	return _callbacks.size();
}

bool Event::Contains(Callback callback) {
	return std::find(_callbacks.begin(), _callbacks.end(), callback) != _callbacks.end();
}

