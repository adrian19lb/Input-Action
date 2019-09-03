#include <gtest/gtest.h>
#include <events/EventComponent.hpp>
#include <events/KeyboardKeyComponent.hpp>

namespace inact::testing {
    
    using EventComponentShrPtr = std::shared_ptr<EventComponent>;

    class EventComponentParameterizedTestFixture : public ::testing::TestWithParam< std::tuple<EventComponentShrPtr, EventComponentShrPtr> > {
    };

    TEST_P(EventComponentParameterizedTestFixture, testEqual) {
        auto baseEvent = std::get<0>(GetParam()); 
        auto comparableEvent = std::get<1>(GetParam());

        EXPECT_FALSE(*baseEvent == *comparableEvent);
    }

    TEST_P(EventComponentParameterizedTestFixture, testHash) {
        auto baseEvent = std::get<0>(GetParam()); 
        auto comparableEvent = std::get<1>(GetParam());

        EXPECT_NE( baseEvent->hash(), comparableEvent->hash() );
    }

    INSTANTIATE_TEST_SUITE_P(
        EventComponentsTest,
        EventComponentParameterizedTestFixture,
        ::testing::Values(
            std::make_tuple( std::make_shared<EventComponent>(Event::Type::KeyPressed), std::make_shared<EventComponent>(Event::Type::KeyReleased)),
            std::make_tuple( std::make_shared<KeyboardKeyComponent<char> >(ButtonAction::PressOnce, 'A'),
                             std::make_shared<KeyboardKeyComponent<char>>(ButtonAction::PressOnce, 'B')))

        );

}
