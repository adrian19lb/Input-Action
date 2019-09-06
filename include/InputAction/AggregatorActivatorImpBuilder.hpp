#ifndef AGGREGATORACTIVATORIMPBUILDER_H
#define AGGREGATORACTIVATORIMPBUILDER_H

#include <aggup/AggregatorActivatorImp.hpp>
#include <events/ButtonListener.hpp>
#include <events/KeyboardKeyListenerFactory.hpp>
#include <events/MouseButtonListenerFactory.hpp>
#include <array>

namespace inact {

    template<typename Indentifier>
    class AggregatorActivatorImpBuilder {
        using ListenerUPtr = std::unique_ptr< aggup::Listener<EventComponentShrPtr> >;
        template<size_t N> using ListenersArrayUPtr = std::unique_ptr< std::array<ListenerUPtr,N> >;
        using AggregatorActivatorUPtr = std::unique_ptr<aggup::AggregatorActivator<Indentifier, EventComponentShrPtr> >; 
    public:
        template<typename... ButtonFactoryType>
        AggregatorActivatorUPtr create() {
            std::tuple<ButtonFactoryType...> factories( std::forward<ButtonFactoryType>( ButtonFactoryType() )...  );
            auto listeners = createListeners< sizeof...(ButtonFactoryType) >(factories);
            auto indices = std::index_sequence_for<ButtonFactoryType...>{};
            auto aggregatorActivator = create(indices, *listeners);
            
            return std::move(aggregatorActivator);
        }
    private:
        template<size_t N, size_t... I>
        AggregatorActivatorUPtr create(std::index_sequence<I...>, std::array<ListenerUPtr, N>& array) {
            return std::make_unique< aggup::AggregatorActivatorImp<Indentifier, EventComponentShrPtr> >( std::move(array[I])... ); 
        }

        template<size_t N, typename... ButtonFactoryType>
        ListenersArrayUPtr<N> createListeners(std::tuple<ButtonFactoryType... > & factories) {
            auto listeners = std::make_unique< std::array<ListenerUPtr, N> >();
            int counter = 0;
            for_each_in_tuple(factories, [&listeners, &counter](auto& factory) {
                    typedef typename std::remove_reference<decltype(factory)>::type::value_type value_type;
                    auto receiver = factory.createReceiver();
                    auto state = factory.createState();
                    auto listener = std::make_unique< ButtonListener<value_type>>( std::move(receiver) );
                    listener->set( std::move(state) );
                    listeners->at(counter) = std::move(listener);
                    ++counter;
            }); 

            return std::move(listeners);
        }

        template<class F, class... Ts, std::size_t... Is>
        void for_each_in_tuple(std::tuple<Ts...> & tuple, F func, std::index_sequence<Is...>){
            using expander = int[];
            (void)expander { 0, ((void)func(std::get<Is>(tuple)), 0)... };
        }

        template<class F, class...Ts>
        void for_each_in_tuple(std::tuple<Ts...> & tuple, F func) {
            for_each_in_tuple(tuple, func, std::make_index_sequence<sizeof...(Ts)>());
        }
    };

}

#endif /* AGGREGATORACTIVATORIMPBUILDER_H */
