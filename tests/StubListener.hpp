#ifndef STUBLISTENER_H
#define STUBLISTENER_H

#include <aggup/Listener.hpp>
#include <FakeEventComponent.hpp>

namespace inact::testing {

    template<typename T> 
    class StubListener : public aggup::Listener<EventComponentShrPtr> {
    public:
        StubListener(T id)
        : id{id} {
        
        }

        EventComponentShrPtr listen() override {
            return std::make_shared< FakeEventComponent<T> >(id);
        }
    private:
        T id;
    
    };

}

#endif /* STUBLISTENER_H */
