#include <Action.hpp>
#include <detail/Hasher.hpp>
#include <detail/Comperator.hpp>
#include <aggup/UnorderedAggregator.hpp>

namespace inact {
        
    using CustomUnorderedAggregator = aggup::UnorderedAggregator< EventComponentShrPtr,
                                                                  detail::Hasher<EventComponentShrPtr>,
                                                                  detail::Comperator<EventComponentShrPtr> >;
    Action::Action() {
        aggregator = createAggregator();
    }

    std::unique_ptr< aggup::Aggregator<EventComponentShrPtr> > Action::createAggregator() {
        return std::make_unique<CustomUnorderedAggregator>();
    }

    bool Action::contain(EventComponentShrPtr const& event) const {
        return aggregator->contain(event); 
    }

    bool Action::contain(Action const& action) const {
        return aggregator->contain(*action.aggregator);
    }

    size_t Action::size() const {
        return aggregator->size();
    }


}
