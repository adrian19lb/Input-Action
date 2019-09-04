#include <gtest/gtest.h>
#include <events/button/HoldState.hpp>
#include <events/button/KeyboardDispatcher.hpp>

namespace inact::button::testing {

    class HoldStateTest : public ::testing::Test {
    public:
        HoldStateTest()
        : current('A')
        , previous('A') {
        
        }
    
    public:
        Fixture<char> current;
        Fixture<char> previous;
    };
    
    
    TEST_F(HoldStateTest, testCreateHoldKeyEventIfActive) {
        HoldState<char, KeyboardDispatcher> state;

        auto eventHoldKey = state.create(current, previous);
        EXPECT_EQ( *eventHoldKey, ButtonComponent<char>(std::make_unique<KeyboardDispatcher>(), ButtonAction::Hold, 'A'));
    }
    
    TEST_F(HoldStateTest, testCreateDefaultEventIfNoActive) {
        HoldState<char, KeyboardDispatcher> state;
        current.isPressed = false;
        auto eventDefault = state.create(current, previous);
        
        EXPECT_EQ( *eventDefault, EventComponent());
    }

}
