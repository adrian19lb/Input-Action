#ifndef BUTTON_LISTENER_FACTORY_HPP
#define BUTTON_LISTENER_FACTORY_HPP 

#include <events/button/PressOnceState.hpp>
#include <events/button/HoldState.hpp>
#include <events/button/ReleaseState.hpp>
#include <events/button/PressSecondState.hpp>
#include <events/button/FixtureReceiver.hpp>

namespace inact {

    namespace button {
        template<typename T, typename... Opt>
        using FixtureReceiverUPtr = std::unique_ptr< FixtureReceiver<T, Opt...> >; 
    }
    
    template<typename T, typename DispatcherType>
    class ButtonListenerFactory {
    public:
        typedef T value_type;
    public:
        button::StateUPtr<T> createState() {
            auto state = std::make_unique< button::PressOnceState<T, DispatcherType>>();
            auto releaseKeyState = std::make_unique< button::ReleaseState<T, DispatcherType> >();
            auto holdKeyState = std::make_unique< button::HoldState<T, DispatcherType>>();
            auto pressSecondKeyState = std::make_unique< button::PressSecondState<T, DispatcherType>>();
            add(state.get(), std::move(releaseKeyState), std::move(holdKeyState), std::move(pressSecondKeyState));

            return std::move(state);
        }

    private:
        template<typename... AdditiveStates>
        void add(button::State<T>* base, AdditiveStates... toAdd) {
            ( base->add( std::move(toAdd) ),... );
        }

    public:
        virtual button::FixtureReceiverUPtr<T> createReceiver() const = 0;
    };

}

#endif /* ifndef BUTTON_LISTENER_FACTORY_HPP */
