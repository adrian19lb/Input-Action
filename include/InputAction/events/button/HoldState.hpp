#ifndef HOLDCREATOR_H
#define HOLDCREATOR_H

#include <events/button/State.hpp>
#include <events/ButtonComponent.hpp>

namespace inact::button {
    
    template<typename T, typename DispatcherType>
    class HoldState : public State<T> {
    public:
        HoldState()
        : State<T>() {
        
        }
       
        ~HoldState() = default;

        EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) override {
            if ( (current.isPressed && previous.isPressed) && (current.code == previous.code) ){ 
                auto dispatcher = std::make_unique<DispatcherType>();
                return std::make_shared< ButtonComponent<T> >(std::move(dispatcher), ButtonAction::Hold, current.code);
            }else {
                return State<T>::create(current, previous);
            }
        }
    };

}

#endif /* HOLDCREATOR_H */
