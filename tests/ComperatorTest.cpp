#include <gtest/gtest.h>
#include <detail/Comperator.hpp>
#include <FakeEventComponent.hpp>

using inact::testing::FakeEventComponent;
using inact::testing::EventComponentShrPtr;

namespace inact::detail::testing {

    TEST(ComperatorTest, testCompareSharedPointer) {
        Comperator< EventComponentShrPtr > comperator;
        auto baseEvent = std::make_shared< FakeEventComponent<int> >(1);
        auto baseClonedEvent = std::make_shared< FakeEventComponent<int> >(1);

        EXPECT_TRUE( comperator(baseEvent, baseClonedEvent) ); 
    }


}
