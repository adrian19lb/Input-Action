#include <gtest/gtest.h>
#include <events/button/FixtureRangeReceiver.hpp>

namespace inact::button::testing {
    
    bool isKeyPressed(char key) {
        return key == 'B';
    }

    TEST(FixtureRangeReceiverTest, testReceiveFixture) {
        FixtureRangeReceiver<char> receiver(isKeyPressed, 'A', 'F');
        auto key = receiver.receive();
        
        EXPECT_TRUE(key.isPressed);
        EXPECT_EQ(key.code, 'B');
    }
}
