#include <gtest/gtest.h>
#include <detail/Hasher.hpp>
#include <FakeEventComponent.hpp>

using inact::testing::FakeEventComponent;

namespace inact::detail::testing {
    
    using EventComponentShrPtr = std::shared_ptr<EventComponent>;

    TEST(HasherTest, testHashSharedPointer) {
        Hasher<EventComponentShrPtr> hasher;
        auto baseHashableEvent = std::make_shared< FakeEventComponent<int> >(1);
        auto clonedHashableEvent = std::make_shared< FakeEventComponent<int> >(1);

        EXPECT_EQ( hasher(baseHashableEvent), hasher(clonedHashableEvent) ); 
    }


}
