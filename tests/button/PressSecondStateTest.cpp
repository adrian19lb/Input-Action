#include <gtest/gtest.h>
#include <events/button/PressSecondState.hpp>
#include <events/button/KeyboardDispatcher.hpp>

namespace inact::button::testing {

    class PressSecondStateTest : public ::testing::Test {
    public:
        PressSecondStateTest()
        : current('A')
        , previous('B') {

        }
    
    public:
        Fixture<char> current;
        Fixture<char> previous;
    };
    
    
    TEST_F(PressSecondStateTest, testCreatePressSecondKeyEventIfActive) {
        PressSecondState<char, KeyboardDispatcher> state;

        auto eventPressSecondKey = state.create(current, previous);
        EXPECT_EQ( *eventPressSecondKey, ButtonComponent<char>(std::make_unique<KeyboardDispatcher>(), ButtonAction::PressOnce, 'A'));
    }
    
    TEST_F(PressSecondStateTest, testCreateDefaultEventIfNoActive) {
        PressSecondState<char, KeyboardDispatcher> state;
        previous.isPressed = false;
        auto eventDefault = state.create(current, previous);
        
        EXPECT_EQ( *eventDefault, EventComponent());
    }

}
