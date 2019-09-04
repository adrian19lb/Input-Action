#include <gtest/gtest.h>
#include <events/button/ReleaseState.hpp>
#include <events/button/KeyboardDispatcher.hpp>

namespace inact::button::testing {

    class ReleaseStateTest : public ::testing::Test {
    public:
        ReleaseStateTest()
        : current('A')
        , previous('B') {
            current.isPressed = false;
        }
    
    public:
        Fixture<char> current;
        Fixture<char> previous;
    };
    
    
    TEST_F(ReleaseStateTest, testCreateReleaseKeyEventIfActive) {
        ReleaseState<char, KeyboardDispatcher> state;

        auto eventReleaseKey = state.create(current, previous);
        EXPECT_EQ( *eventReleaseKey, ButtonComponent<char>(std::make_unique<KeyboardDispatcher>(), ButtonAction::Release, 'B'));
    }
    
    TEST_F(ReleaseStateTest, testCreateDefaultEventIfNoActive) {
        ReleaseState<char, KeyboardDispatcher> state;
        current.isPressed = true;
        auto eventDefault = state.create(current, previous);
        
        EXPECT_EQ( *eventDefault, EventComponent());
    }

}
