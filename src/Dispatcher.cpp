#include <events/button/Dispatcher.hpp>

namespace inact::button {

    void Dispatcher::map(ButtonAction action, Event::Type event) {
        mapper[action] = event;
    }

    Event::Type Dispatcher::get(ButtonAction action) const {
        return mapper[action];
    }

    Dispatcher::Dispatcher(Dispatcher const& dispatcher) {
        copyMapper(dispatcher.mapper);
    }

    Dispatcher& Dispatcher::operator=(Dispatcher const& dispatcher) {
        copyMapper(dispatcher.mapper);

        return *this;
    }

    void Dispatcher::copyMapper(Event::Type const* inputMapper) {
        for (int i = ButtonAction::PressOnce; i < ButtonAction::Unknown; ++i) {
            mapper[i] = inputMapper[i];
        }
    }

}
