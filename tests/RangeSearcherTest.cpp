#include <gtest/gtest.h>
#include <detail/RangeSearcher.hpp>

namespace inact::detail::testing {
    
    TEST(RangeSearcherTest, testSearch) {
        detail::RangeSearcher< bool(*)(char), char> searcher( [](char key) { return key == 'B';} );
        auto key = searcher('B', 'F');
        
        EXPECT_EQ('B', key);
    }

}
