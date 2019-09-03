#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <events/EventComponent.hpp>
#include <events/ButtonAction.hpp>
#include <memory>

namespace inact {
    
    namespace button {
        class Dispatcher;
        using DispatcherUPtr = std::unique_ptr<Dispatcher>;
    }

    template<typename T>
    class ButtonComponent : public EventComponent {
    public:
        const T code;
    public:
        ButtonComponent(button::DispatcherUPtr dispatcher, ButtonAction action, T code);
        ButtonComponent(ButtonComponent<T> const& button);
        ButtonComponent<T>& operator=(ButtonComponent<T> const& button);
        size_t hash() const override;
    protected:
        bool isEqual(EventComponent const& event) const override;
    private:
        button::DispatcherUPtr dispatcher;
    };

}

#include <events/button/ButtonComponent.inc>

#endif /* ifndef BUTTON_HPP */
