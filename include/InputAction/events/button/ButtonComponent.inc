#include <detail/hash_combine.hpp>
#include <events/button/Dispatcher.hpp>

namespace inact {
    
    template<typename T> ButtonComponent<T>::ButtonComponent(button::DispatcherUPtr dispatcher, ButtonAction action, T code)
    : EventComponent( dispatcher->get(action) )
    , code{code}
    , dispatcher( std::move(dispatcher) ) {

    }

    template<typename T> ButtonComponent<T>::ButtonComponent(ButtonComponent const& button)
    : EventComponent(button)
    , code(button.code)
    , dispatcher( std::make_unique<button::Dispatcher>(*button.dispatcher) ) {

    }
    
    template<typename T> ButtonComponent<T>& ButtonComponent<T>::operator=(ButtonComponent<T> const& button) {
        EventComponent::operator=(button);
        code = button.code;
        dispatcher = std::make_unique<button::Dispatcher>(*button.dispatcher);

        return *this; 
    }
    
    template<typename T> size_t ButtonComponent<T>::hash() const {
        size_t seed = EventComponent::hash();
        detail::hash_combine(seed, code);

        return seed;
    }
    
    template<typename T> bool ButtonComponent<T>::isEqual(EventComponent const& event) const {
        if ( ButtonComponent<T> const* e = dynamic_cast< ButtonComponent<T> const* >(&event) ) {
            return EventComponent::isEqual(event) && code == e->code;
        }else {
            return false;
        }
    }
}
