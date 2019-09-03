#ifndef KEYBOARD_KEY_COMPONENT
#define KEYBOARD_KEY_COMPONENT

#include <events/ButtonComponent.hpp>

namespace inact {

    template<typename T>
    class KeyboardKeyComponent : public ButtonComponent<T> {
    public:
        KeyboardKeyComponent(ButtonAction action, T code);
        KeyboardKeyComponent(KeyboardKeyComponent const& event);
        KeyboardKeyComponent& operator=(KeyboardKeyComponent const& event);
    };
}

#include <events/button/KeyboardKeyComponent.inc>

#endif /* ifndef KEYBOARD_KEY_COMPONENT */
