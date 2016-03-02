#pragma once
#include <functional>
#include <list>

class Event final {
public:
	class Callback final {
	public:
		Callback(Event&, std::function<void(Event*)>);
		~Callback();

		void operator()(Event*);
		bool operator==(const Callback&);
		bool operator!=(const Callback&);

		std::list<Callback>::size_type GetID();
	private:
		std::list<Callback>::size_type _id;
		std::function<void(Event*)> _func;
	};

	Callback Attach(std::function<void(Event*)>);
	void Detach(Callback);
	void Notify();

	std::list<Callback>::size_type Size();
	bool Contains(Callback);
private:
	std::list<Callback>::size_type _idCounter = 0;
	std::list<Callback> _callbacks;
};