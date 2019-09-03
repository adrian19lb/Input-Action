#ifndef EVENT_HPP
#define EVENT_HPP

#include <events/Identifiers.hpp>
#include <cstddef>
#include <memory>

namespace inact {

    class EventComponent {
    public:
        EventComponent(Event::Type type = Event::Type::Unknown);
        EventComponent(EventComponent const& event);
        EventComponent& operator=(EventComponent const& event);
        friend bool operator==(EventComponent const& lhs, EventComponent const& rhs);
        Event::Type type() const;
        virtual size_t hash() const;
    protected:
        void set(Event::Type type);
        virtual bool isEqual(EventComponent const& event) const;
    private:
        Event::Type id;
    };

    using EventComponentShrPtr = std::shared_ptr<EventComponent>;

}

#endif /* ifndef EVENT_HPP */
