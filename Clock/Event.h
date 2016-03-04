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

		std::list<Callback>::size_type GetID() const;
	private:
		const std::list<Callback>::size_type _id;
		const std::function<void(Event*)> _func;
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

bool operator==(const Event::Callback& lhs, const Event::Callback& rhs);
bool operator!=(const Event::Callback& lhs, const Event::Callback& rhs);