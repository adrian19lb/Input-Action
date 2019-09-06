#include <ButtonActionActivator.hpp>
#include <gtest/gtest.h>
#include <StubListener.hpp>

namespace inact::testing {
    
    template<typename Identifiers>
    class ButtonActionActivatorWithStubListeners : public ButtonActionActivator<Identifiers> {
        template<typename Id, typename T>
        using AggregatorActivatorUPtr = std::unique_ptr< aggup::AggregatorActivator<Id, T> >;
    public:
        ButtonActionActivatorWithStubListeners()
        : ButtonActionActivator<Identifiers>() {
            auto aggregator = createAggregatorActivator();
            ButtonActionActivator<Identifiers>::setAggregatorActivator( std::move(aggregator) ); 
        }
    private:
        AggregatorActivatorUPtr<Identifiers, EventComponentShrPtr> createAggregatorActivator() {
            auto listenerA = std::make_unique< testing::StubListener<char> >('A');
            auto listenerB = std::make_unique< testing::StubListener<char> >('B');
            auto aggregatorActivator = std::make_unique<aggup::AggregatorActivatorImp<Identifiers, EventComponentShrPtr>>(std::move(listenerA), std::move(listenerB));

            return std::move(aggregatorActivator);
        }
    };

    TEST(ButtonActionActivatorTest, updateTest) {
        Action action;
        action.add<FakeEventComponent, char>('A');
        action.add<FakeEventComponent, char>('B');
        
        ButtonActionActivatorWithStubListeners<std::string> activator; 
        activator.add("test", action);
        activator.update();
         
        EXPECT_TRUE( activator["test"] );
    }

}
