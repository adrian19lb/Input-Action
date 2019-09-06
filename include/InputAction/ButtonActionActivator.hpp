#ifndef BUTTONACTIONACTIVATOR_H
#define BUTTONACTIONACTIVATOR_H

#include <ActionActivator.hpp>
#include <AggregatorActivatorImpBuilder.hpp>

namespace inact {
    
    template<typename Identifiers>
    class ButtonActionActivator : public ActionActivator<Identifiers> {
        template<typename Id, typename T>
        using AggregatorActivatorUPtr = std::unique_ptr< aggup::AggregatorActivator<Id, T> >;
    public:
        ButtonActionActivator() {
            aggregatorActivator = std::move( createAggregatorActivator() );
        }

    private:
    //TODO:Add joystick button listener
        AggregatorActivatorUPtr<Identifiers, EventComponentShrPtr> createAggregatorActivator() {
            return std::move( builder.template create<KeyboardKeyListenerFactory, MouseButtonListenerFactory>() );
        }

    protected:
        void setAggregatorActivator(AggregatorActivatorUPtr<Identifiers, EventComponentShrPtr> aggregatorActivator) {
            this->aggregatorActivator = std::move(aggregatorActivator); 
        }
    public:
        void add(Identifiers id, Action const& action) override {
            auto const* aggregator = &action.get();
            aggregatorActivator->add(id, aggregator); 
        }

        void update() override {
            aggregatorActivator->update();
        }

        bool operator[](Identifiers id) override {
            return aggregatorActivator->operator[](id);
        } 

    private:
        AggregatorActivatorUPtr<Identifiers, EventComponentShrPtr> aggregatorActivator;
        AggregatorActivatorImpBuilder<Identifiers> builder;
    };

}

#endif /* ACTIONACTIVATOR_H */
