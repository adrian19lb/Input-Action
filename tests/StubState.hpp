#ifndef STUBSTATE_HPP
#define STUBSTATE_HPP

#include <events/button/State.hpp>
#include <FakeEventComponent.hpp>

namespace inact::button::testing {
    
    using inact::testing::FakeEventComponent;
    
    template<typename T>
    class StubState : public State<T> {
    public:
        StubState(T id)
        : id{id} {
        
        }

        EventComponentShrPtr create(Fixture<T> const& current, Fixture<T> const& previous) override {
            return std::make_shared< FakeEventComponent<T> >(id);
        }
    private:
        T id;
    };

}


#endif /* ifndef STUBSTATE_HPP */
