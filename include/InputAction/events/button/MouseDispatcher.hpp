#ifndef MOUSE_DISPATCHER_HPP
#define MOUSE_DISPATCHER_HPP 

#include <events/button/Dispatcher.hpp>

namespace inact::button {

    class MouseDispatcher : public Dispatcher {
    public:
        MouseDispatcher();
        ~MouseDispatcher() = default;
        MouseDispatcher(MouseDispatcher const& dispatcher);
        MouseDispatcher& operator=(MouseDispatcher const& dispatcher);
        DispatcherUPtr clone() override;
    };

}

#endif /* ifndef MOUSE_DISPATCHER_HPP */
