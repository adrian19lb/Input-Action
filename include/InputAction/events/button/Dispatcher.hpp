#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <memory>
#include <events/ButtonAction.hpp>
#include <events/Identifiers.hpp>

namespace inact::button {
    
    class Dispatcher;

    using DispatcherUPtr = std::unique_ptr< Dispatcher >;

    class Dispatcher {
    public:
        Dispatcher() = default; 
        virtual ~Dispatcher() = default;
        Dispatcher(const Dispatcher& dispatcher);
        Dispatcher& operator=(const Dispatcher& dispatcher);
        virtual DispatcherUPtr clone() = 0;
        Event::Type get(ButtonAction action) const;
    protected:
        void map(ButtonAction action, Event::Type event);
        void copyMapper(Event::Type const* mapper);
    private:
        Event::Type mapper[3];
    };

}

#endif /* DISPATCHER_H */
