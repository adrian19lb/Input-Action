#include <events/button/KeyboardDispatcher.hpp>

namespace inact::button {

    KeyboardDispatcher::KeyboardDispatcher()
    : Dispatcher() {
        Dispatcher::map(ButtonAction::PressOnce, Event::Type::KeyPressed);
        Dispatcher::map(ButtonAction::Release, Event::Type::KeyReleased);
        Dispatcher::map(ButtonAction::Hold, Event::Type::KeyHold);
    }

    KeyboardDispatcher::KeyboardDispatcher(KeyboardDispatcher const& dispatcher)
    : Dispatcher(dispatcher) {
    
    }

    KeyboardDispatcher& KeyboardDispatcher::operator=(KeyboardDispatcher const& dispatcher) {
        Dispatcher::operator=(dispatcher);
        
        return *this;
    }

    DispatcherUPtr KeyboardDispatcher::clone() {
        return std::make_unique<KeyboardDispatcher>(*this);
    }

}
