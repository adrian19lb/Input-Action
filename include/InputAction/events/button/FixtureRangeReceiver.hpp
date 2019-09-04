#ifndef RANGERECEIVER_H
#define RANGERECEIVER_H

#include <events/button/FixtureReceiver.hpp>
#include <detail/RangeSearcher.hpp>
#include <type_traits>

namespace inact::button {

    template<typename T, typename... Opt>
    using PressResponser = bool(*)(T, Opt&&...);
    
    template<typename T, typename... Opt>
    class FixtureRangeReceiver : public FixtureReceiver<T, Opt...> { 
    public:
        template<typename Functor> FixtureRangeReceiver(Functor functor, T first, T last)
        : receiver( std::forward<Functor>(functor) )
        , first{first}
        , last{last} {
            static_assert( std::is_same<Functor, PressResponser<T, Opt&&...> >::value, "Functor must be type of PressResponser<T, Opt&&... >");
        }

        ~FixtureRangeReceiver() = default;

        FixtureRangeReceiver(FixtureRangeReceiver const& receiver) = delete;

        FixtureRangeReceiver& operator=(FixtureRangeReceiver const& receiver) = delete;

        FixtureRangeReceiver(FixtureRangeReceiver&& receiver)
        : first{ std::move(receiver.first) }
        , last{ std::move(receiver.last) }
        , receiver{ std::move(receiver.receiver) } {
        
        }

        FixtureRangeReceiver& operator=(FixtureRangeReceiver&& rhs) {
            first = std::move(rhs.first);
            last = std::move(rhs.last);
            receiver = std::move(rhs.receiver);

            return *this;
        }

        Fixture<T> receive(Opt&&... optional) override {
            Fixture<T> button;
            button.code = receiver( first, last, std::forward<Opt>(optional)... );
            button.isPressed = isPressed(button.code);

            return button;
        }
    private:
        bool isPressed(T const& button) {
            if (button != last) {
                return true;
            }else {
                return false;
            }
        } 
    private:
        T first;
        T last;
        detail::RangeSearcher< PressResponser<T, Opt&&...>, T> receiver;
    };
        
}

#endif /* RANGERECEIVER_H */
