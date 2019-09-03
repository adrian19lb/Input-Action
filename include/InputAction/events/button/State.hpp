#ifndef STATE_H
#define STATE_H

#include <events/button/Fixture.hpp>
#include <memory>

namespace inact {
    
    class EventComponent;
    
    using EventComponentShrPtr = std::shared_ptr<EventComponent>;
}

namespace inact::button {   
  
    template<typename T>
    class State;
    
    template<typename T>
    using StateUPtr = std::unique_ptr< State<T> >;

    template<typename T>
    class State {
    public:
        State()
        : next(nullptr) {
        
        }

        virtual ~State() = default;

        virtual EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) {
            if (next) {
                return next->create(current, previous);
            }else {
                return std::make_shared<EventComponent>();
            }
        }

        virtual void add(StateUPtr<T> state) {
            if (!next) { 
                next = std::move(state); 
            }else {
                next->add( std::move(state) );
            }
        }

    private:
        StateUPtr<T> next;
    };

}

#endif /* STATE_H */
