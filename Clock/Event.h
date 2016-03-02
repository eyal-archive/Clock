#pragma once
#include <functional>
#include <list>

class Event final {
public:
	class Callback final {
	public:
		explicit Callback(std::function<void(Event*)>);
		~Callback();
		void operator()(Event*);
	private:
		std::function<void(Event*)> _func;
	};

	Callback Attach(std::function<void(Event*)>);
	void Detach(Callback);
	void Notify();
private:
	std::list<Callback> _callbacks;
};