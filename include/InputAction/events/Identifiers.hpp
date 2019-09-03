#ifndef IDENTIFIERS_HPP
#define IDENTIFIERS_HPP

namespace inact::Event {

    enum class Type {
        KeyPressed,
        KeyReleased,
        KeyHold,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseButtonHold,
        JoystickButtonPressed,
        JoystickButtonReleased,
        JoystickButtonHold,
        JoystickConnect,
        JoystickDisconnect,
        MouseMove,
        JoystickMove,
        TouchBegan,
        TouchMoved,
        TouchEnded,
        Unknown
    };

}

#endif /* ifndef IDENTIFIERS_HPP */
