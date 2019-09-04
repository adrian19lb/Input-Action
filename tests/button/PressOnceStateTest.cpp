#include <gtest/gtest.h>
#include <events/button/PressOnceState.hpp>
#include <events/button/KeyboardDispatcher.hpp>

namespace inact::button::testing {

    class PressOnceStateTest : public ::testing::Test {
    public:
        PressOnceStateTest()
        : current('A')
        , previous('B') {
        
        }
    
    public:
        Fixture<char> current;
        Fixture<char> previous;
    };
    
    
    TEST_F(PressOnceStateTest, testCreatePressOnceIfActive) {
        PressOnceState<char, KeyboardDispatcher> state;
        previous.isPressed = false;

        auto eventPressKey = state.create(current, previous);
        EXPECT_EQ( *eventPressKey, ButtonComponent<char>(std::make_unique<KeyboardDispatcher>(), ButtonAction::PressOnce, 'A'));
    }
    
    TEST_F(PressOnceStateTest, testCreatePressOnceIfNoActive) {
        PressOnceState<char, KeyboardDispatcher> state;
        auto eventDefault = state.create(current, previous);
        
        EXPECT_EQ( *eventDefault, EventComponent());
    }

}
