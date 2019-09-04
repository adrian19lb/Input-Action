#ifndef FIXTURERECEIVER_H
#define FIXTURERECEIVER_H

#include <events/button/Fixture.hpp>

namespace inact::button {
    
    template<typename T, typename... Opt>
    class FixtureReceiver {
    public:
        virtual ~FixtureReceiver() = default;

        virtual Fixture<T> receive(Opt&&... opt) {
            return Fixture<T>();
        }
    };

}

#endif /* FIXTURERECEIVER_H */
