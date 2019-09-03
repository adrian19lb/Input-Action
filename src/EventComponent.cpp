#include <events/EventComponent.hpp>
#include <detail/hash_combine.hpp>

namespace inact {

    EventComponent::EventComponent(Event::Type type)
    : id{type} {
    
    }

    EventComponent::EventComponent(const EventComponent& event)
    : id{event.id} {
    }

    EventComponent& EventComponent::operator=(const EventComponent& event) {
        id = event.id;

        return *this;
    }

    void EventComponent::set(Event::Type type) {
        id = type; 
    }

    Event::Type EventComponent::type() const {
        return id;
    }

    bool operator==(const EventComponent& lhs, const EventComponent& rhs) {
        return lhs.isEqual(rhs); 
    }

    bool EventComponent::isEqual(const EventComponent& event) const {
        return id == event.id;  
    }

    size_t EventComponent::hash() const {
        std::size_t seed = 0;
        detail::hash_combine(seed, id);

        return seed;
    }

}
