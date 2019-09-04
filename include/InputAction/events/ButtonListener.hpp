#ifndef BUTTONLISTENER_HPP
#define BUTTONLISTENER_HPP

#include <aggup/Listener.hpp>
#include <events/button/State.hpp>
#include <events/button/FixtureReceiver.hpp>
#include <events/EventComponent.hpp>
#include <detail/Buffer.hpp>

namespace inact::button {
    
    template<typename T, typename... Opt>
    using FixtureReceiverUPtr = std::unique_ptr< FixtureReceiver<T, Opt...> >;

}

namespace inact {
   
    template<typename T, typename... Opt>
    class ButtonListener : public aggup::Listener<EventComponentShrPtr> {
    public:
        ButtonListener(button::FixtureReceiverUPtr<T, Opt...> receiver, Opt&&... opt)
        : receiver( std::move(receiver) )
        , optionalReceiverArgs( std::forward<Opt>(opt)... ) {
            buttonsBuffer.backup( button::Fixture<T>() );
        }
        
        ~ButtonListener() = default;
        
        void set(button::StateUPtr<T> state) {
            this->state = std::move(state); 
        }

        EventComponentShrPtr listen() override {
            constexpr auto tupleSize = std::tuple_size_v< decltype(optionalReceiverArgs) >;
            auto receivedButton = listen_helper( std::make_index_sequence<tupleSize>() );
            auto event = transform( receivedButton, buttonsBuffer.top() ); 
            buttonsBuffer.backup(receivedButton);

            return event;
        }

    private:
        template<std::size_t... Is> button::Fixture<T> listen_helper(std::index_sequence<Is...>) {
            auto receivedButton = receiver->receive( std::forward<Opt>( std::get<Is>(optionalReceiverArgs))... );
            return receivedButton;
        }

        EventComponentShrPtr transform(button::Fixture<T> const& current, button::Fixture<T> const& previous) {
            return state->create(current, previous);
        }

    private:
        button::StateUPtr<T> state;
        detail::Buffer<5, button::Fixture<T> > buttonsBuffer;
        button::FixtureReceiverUPtr<T, Opt...> receiver;
        std::tuple<Opt...> optionalReceiverArgs;
    };

}

#endif /* ifndef BUTTONLISTENER_HPP */
