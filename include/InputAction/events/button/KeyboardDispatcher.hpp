#ifndef KEYBOARDDISPATCHER_H
#define KEYBOARDDISPATCHER_H

#include <events/button/Dispatcher.hpp>

namespace inact::button {

    class KeyboardDispatcher : public Dispatcher {
    public:
        KeyboardDispatcher();
        KeyboardDispatcher(KeyboardDispatcher const& dispatcher);
        KeyboardDispatcher& operator=(KeyboardDispatcher const& dispatcher);
        DispatcherUPtr clone() override;
    };

}

#endif /* KEYBOARDDISPATCHER_H */
