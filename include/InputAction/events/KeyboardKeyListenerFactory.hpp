#ifndef KEYBOARDKEYLISTENERFACTORY_H
#define KEYBOARDKEYLISTENERFACTORY_H

#include <events/ButtonListenerFactory.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <events/button/KeyboardDispatcher.hpp>
#include <events/button/FixtureRangeReceiver.hpp>

namespace inact {

    class KeyboardKeyListenerFactory : public ButtonListenerFactory<sf::Keyboard::Key, button::KeyboardDispatcher> {
    public:
       button::FixtureReceiverUPtr<sf::Keyboard::Key> createReceiver() const override {
            return std::make_unique< button::FixtureRangeReceiver<sf::Keyboard::Key> >(sf::Keyboard::isKeyPressed, sf::Keyboard::A, sf::Keyboard::KeyCount); 
       } 
    };

}



#endif /* KEYBOARDKEYLISTENERFACTORY_H */
