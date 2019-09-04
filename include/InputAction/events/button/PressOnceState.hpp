#ifndef PRESS_ONCE_CREATOR
#define PRESS_ONCE_CREATOR

#include <events/button/State.hpp>
#include <events/ButtonComponent.hpp>

namespace inact::button {
    
    template<typename T, typename DispatcherType>
    class PressOnceState : public State<T> {
    public:
        PressOnceState()
        : State<T>() {
        
        }
        
        ~PressOnceState() = default;
        
        EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) override {
            if (current.isPressed && !previous.isPressed) {
                auto dispatcher = std::make_unique<DispatcherType>();
                return std::make_shared< ButtonComponent<T> >(std::move(dispatcher), ButtonAction::PressOnce, current.code );
            }else {
                return State<T>::create(current, previous);
            }
        }
    };

}

#endif /* ifndef PRESS_ONCE_CREATOR */
