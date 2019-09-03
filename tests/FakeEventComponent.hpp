#ifndef FAKEEVENT_H
#define FAKEEVENT_H

#include <events/EventComponent.hpp>
#include <detail/hash_combine.hpp>

namespace inact::testing {

    using EventComponentShrPtr = std::shared_ptr<EventComponent>;
    
    template<typename T> 
    class FakeEventComponent : public EventComponent {
    public:
        FakeEventComponent(T id)
        : EventComponent()
        , id(id) {

        }

        FakeEventComponent(FakeEventComponent const& event)
        : EventComponent(event)
        , id{event.id} {

        }

        FakeEventComponent& operator=(FakeEventComponent const& event) {
            EventComponent::operator=(event);
            id = event.id;
            return *this;
        }

        bool isEqual(EventComponent const& event) const override {
            if ( FakeEventComponent const* e = dynamic_cast<FakeEventComponent const*>(&event) ) {
                return EventComponent::isEqual(event) && e->id == id; 
            }else {
                return false;
            }
        }

        size_t hash() const override {
            size_t seed = EventComponent::hash();
            detail::hash_combine(seed, id);

            return seed; 
        }
    private:        
        T id; 
    };

}
#endif /* FAKEEVENT_H */
