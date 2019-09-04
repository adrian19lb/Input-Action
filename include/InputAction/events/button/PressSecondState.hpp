#ifndef PRESSSECONDCREATOR_H
#define PRESSSECONDCREATOR_H

#include <events/button/State.hpp>
#include <events/ButtonComponent.hpp>

namespace inact::button {
    
    template<typename T, typename DispatcherType>
    class PressSecondState : public State<T> {
    public:
        PressSecondState()
        : State<T>() {

        }

        EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) override {
            if ( (current.isPressed && previous.isPressed) && (current.code != previous.code) ) {  
                auto dispatcher = std::make_unique<DispatcherType>();
                return std::make_shared< ButtonComponent<T> >(std::move(dispatcher), ButtonAction::PressOnce, current.code );
            }else {
                return State<T>::create(current, previous);
            }
        }
    };

}

#endif /* PRESSSECONDCREATOR_H */
