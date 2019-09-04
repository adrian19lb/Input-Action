#ifndef MOUSE_BUTTON_COMPONENT
#define MOUSE_BUTTON_COMPONENT

#include <events/ButtonComponent.hpp>
#include <events/button/MouseDispatcher.hpp>

namespace inact {

    template<typename T>
    struct MouseButtonComponent : public ButtonComponent<T> {
        MouseButtonComponent(ButtonAction action, T code)
        : ButtonComponent<T>( std::make_unique<button::MouseDispatcher>(), action, code ) {

        } 
        
        ~MouseButtonComponent() = default;

        MouseButtonComponent(MouseButtonComponent const& event)
        : ButtonComponent<T>(event) {
        
        }

        MouseButtonComponent& operator=(MouseButtonComponent const& event) {
            ButtonComponent<T>::operator=(event);

            return *this;
        }
    };

}

#endif /* ifndef  MOUSE_BUTTON_COMPONENT */
