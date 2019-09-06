#ifndef MOUSEBUTTONLISTENERFACTORY_H
#define MOUSEBUTTONLISTENERFACTORY_H

#include <events/ButtonListenerFactory.hpp>
#include <events/button/MouseDispatcher.hpp>
#include <SFML/Window/Mouse.hpp>
#include <events/button/FixtureRangeReceiver.hpp>

namespace inact {

    class MouseButtonListenerFactory : public ButtonListenerFactory<sf::Mouse::Button, button::MouseDispatcher> {
    public:
       button::FixtureReceiverUPtr<sf::Mouse::Button> createReceiver() const override {
            return std::make_unique< button::FixtureRangeReceiver<sf::Mouse::Button> >(sf::Mouse::isButtonPressed, sf::Mouse::Left, sf::Mouse::ButtonCount); 
       } 
    };


}


#endif /* MOUSEBUTTONLISTENERFACTORY_H */
