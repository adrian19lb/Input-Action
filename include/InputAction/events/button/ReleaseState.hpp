#ifndef RELEASE_CREATOR_HPP
#define RELEASE_CREATOR_HPP

#include <events/button/State.hpp>
#include <events/ButtonComponent.hpp>

namespace inact::button {
    
    template<typename T, typename DispatcherType>
    class ReleaseState : public State<T> {
    public:
        ReleaseState()
        : State<T>() {
        
        }
        ~ReleaseState() = default;

        EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) override {
            if (previous.isPressed && !current.isPressed) {
                auto dispatcher = std::make_unique<DispatcherType>();
                return std::make_shared< ButtonComponent<T> >( std::move(dispatcher), ButtonAction::Release, previous.code );
            }else {
                return State<T>::create(current, previous);
            }
        }
    };

}

#endif /* ifndef RELEASE_CREATOR_HPP */
