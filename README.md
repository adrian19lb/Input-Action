# Input-Action
High level input action library based on SFML/Window module. Actually keyboard and mouse button events are supported.
# Learn
Let's start with simple example. First of all we need include headers:
```
  #include <inact/Action.hpp>
  #include <inact/events/KeyboardKeyEventComponent.hpp>
  #include <inact/events/MouseButtonEventComponent.hpp>
  #include <inact/events/ButtonActionActivator.hpp>
 ```
Now, let's create our 'superJump' action:
```
  inact::Action superJump;
  action.add<inact::KeyboardKeyEventComponent, sf::Keyboard::Key>(inact::ButtonAction::PressOnce, sf::Keyboard::Key::A);
  action.add<inact::MouseButtonEventComponent, sf::Mouse::Button>(inact::ButtonAction::Hold, sf::Mouse::Button::Left);
```
Next step is define ActionActivator instance and add 'superJump' action to activator. We use std::string as action identifier:
```
  inact::ActionActivator activator = new inact::ButtonActionActivator<std::string>();
  activator->add("superJump", superJump);
``` 
Before we check if our action is active we have to call ActionActivator::update() method. This method clear old events, listen new ones and pull them to the ActionActivator:
```
   activator->update();
```
Finally, we can check if our 'superJump' action is detected:
```
  if (activator->operator[]("superJump") ) {
    do some stuff...
  }
```
**Note: Example above must be performed in the application loop to grab events in every single step.**
