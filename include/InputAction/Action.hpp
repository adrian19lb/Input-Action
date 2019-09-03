#ifndef ACTION_H
#define ACTION_H

#include <events/EventComponent.hpp>
#include <aggup/Aggregator.hpp>
#include <memory>

namespace inact {

    using EventComponentShrPtr = std::shared_ptr<EventComponent>;
    
    class Action {
        using AggregatorEventComponentUPtr = std::unique_ptr< aggup::Aggregator<EventComponentShrPtr> >;
    public:
        Action();
    protected:
        virtual AggregatorEventComponentUPtr createAggregator();
    public:
        template< template<typename... T> class EventType, typename... T, typename... Args>
        void add(Args...args) {
            auto newEvent = createEventComponent< EventType<T...> >(std::forward<Args>(args)... );
            aggregator->add(newEvent);
        }
    private: 
        template<typename T, typename... Args>
        std::shared_ptr<T> createEventComponent(Args... args) {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }

    public:
        size_t size() const;
        bool contain(EventComponentShrPtr const& event) const;
        bool contain(Action const& action) const;
    private:
        AggregatorEventComponentUPtr aggregator;
    };

}

#endif /* ACTION_H */
