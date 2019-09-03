#ifndef COMPERATOR_H
#define COMPERATOR_H

#include <detail/Dereferencer.hpp>

namespace inact::detail {

    template<typename E>
    struct Comperator {
    public:
        size_t operator()(E const& lhs, E const& rhs) const {
            return dereferencer(lhs) == dereferencer(rhs);
        }
    private:
        Dereferencer<E> dereferencer;
    };

}

#endif /* COMPERATOR_H */
