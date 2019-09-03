#include <gtest/gtest.h>

#include <Action.hpp>
#include <FakeEventComponent.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace inact::testing {

    TEST(ActionTest, testContain) {
        Action action;
        action.add< FakeEventComponent, char >('A');
        action.add< FakeEventComponent, char >('B');

        Action subAction;
        subAction.add<FakeEventComponent, char>('A');
        
        EXPECT_EQ(action.size(), 2);
        EXPECT_TRUE( action.contain(std::make_shared<FakeEventComponent<char>>('A') ));
        EXPECT_FALSE( action.contain(std::make_shared<FakeEventComponent<char>>('C') ));
        EXPECT_TRUE( action.contain(subAction) );
    }

}
