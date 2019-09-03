#include <gtest/gtest.h>
#include <StubState.hpp>

namespace inact::button::testing {
    
    TEST(StateTest, testCreateIfSubStateIsAdded) {
        State<char> parentState;
        Fixture<char> fixture('A');

        parentState.add( std::make_unique< StubState<char> >('B') );
        auto event = parentState.create(fixture, fixture);
        EXPECT_EQ(FakeEventComponent<char>('B'), *event);
    }

    TEST(StateTest, testCreateIfNoSubStateIsAdded) {
        State<char> parentState;
        Fixture<char> fixture('A');

        auto event = parentState.create(fixture, fixture);
        EXPECT_EQ(EventComponent(), *event);
    }

}
