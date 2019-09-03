#ifndef FIXTURE_HPP
#define FIXTURE_HPP value

namespace inact::button {

    template<typename T> 
    struct Fixture {
        bool isPressed = false;
        T code;

        Fixture() = default;

        Fixture(T code)
        : code{code}
        , isPressed{true} {
        
        }

        ~Fixture() = default;

        Fixture(Fixture const& fixture) {
            copy(fixture);
        }

        Fixture& operator=(Fixture const& fixture) {
            copy(fixture);

            return *this;
        }    
    private:
        void copy(Fixture const& fixture) {
            isPressed = fixture.isPressed;
            code = fixture.code;
        }
    };
}

#endif /* ifndef FIXTURE_HPP */
