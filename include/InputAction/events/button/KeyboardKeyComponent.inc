#include <events/button/KeyboardDispatcher.hpp>

namespace inact {
    
        template<typename T> KeyboardKeyComponent<T>::KeyboardKeyComponent(ButtonAction action, T code)
        : ButtonComponent<T>( std::make_unique<button::KeyboardDispatcher>(), action, code ) {

        }

        template<typename T> KeyboardKeyComponent<T>::KeyboardKeyComponent(KeyboardKeyComponent<T> const& event)
        : ButtonComponent<T>(event) {
        
        }
        
        template<typename T> KeyboardKeyComponent<T>& KeyboardKeyComponent<T>::operator=(KeyboardKeyComponent<T> const& event) {
            ButtonComponent<T>::operator=(event);

            return *this;
        }
}
