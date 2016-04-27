#pragma once
#include <functional>
#include <list>

class Event final {
public:
    class Callback final {
    public:
        explicit Callback(std::function<void(Event*)>);
        ~Callback() = default;

        void operator()(Event*) const;

        std::list<Callback>::size_type GetID() const;
    private:
        const std::list<Callback>::size_type _id;
        const std::function<void(Event*)> _func;
    };

    Event() = default;
    ~Event() = default;

    Callback Attach(std::function<void(Event*)>);
    void Detach(Callback&);
    void Notify();

    std::list<Callback>::size_type Size() const;
    bool Contains(Callback&);
private:
    static std::list<Callback>::size_type _idCounter;
    std::list<Callback> _callbacks;
};

bool operator==(const Event::Callback&, const Event::Callback&);
bool operator!=(const Event::Callback&, const Event::Callback&);
