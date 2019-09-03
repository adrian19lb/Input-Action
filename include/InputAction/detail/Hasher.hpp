#ifndef HASHER_H
#define HASHER_H

#include <detail/Dereferencer.hpp>

namespace inact::detail {
    
    template<typename E>
    class Hasher {
    public:
        size_t operator()(E const& element) const {
            auto& dereferencedValue = Dereferencer<E>()(element);
            return dereferencedValue.hash();
        }
    };

}

#endif /* HASHER_H */
