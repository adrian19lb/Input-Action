#include <events/button/MouseDispatcher.hpp>

namespace inact::button {

    MouseDispatcher::MouseDispatcher() {
        Dispatcher::map(ButtonAction::PressOnce, Event::Type::MouseButtonPressed);
        Dispatcher::map(ButtonAction::Release, Event::Type::MouseButtonReleased);
        Dispatcher::map(ButtonAction::Hold, Event::Type::MouseButtonHold);
    }
    
    MouseDispatcher::MouseDispatcher(MouseDispatcher const& dispatcher)
    : Dispatcher(dispatcher) {
    
    }

    MouseDispatcher& MouseDispatcher::operator=(MouseDispatcher const& dispatcher) {
        Dispatcher::operator=(dispatcher);
        
        return *this;
    }

    DispatcherUPtr MouseDispatcher::clone() {
        return std::make_unique<MouseDispatcher>(*this);
    }

}
