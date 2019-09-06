#ifndef ACTIONACTIVATOR_H
#define ACTIONACTIVATOR_H

#include <Action.hpp>

namespace inact {
    
    template<typename Identifiers>
    class ActionActivator {
    public:
        virtual ~ActionActivator() = default;
        virtual void add(Identifiers id, Action const& action) = 0;
        virtual void update() = 0;
        virtual bool operator[](Identifiers id) = 0;
    
    };
}

#endif /* ACTIONACTIVATOR_H */
