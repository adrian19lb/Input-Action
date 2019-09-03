#ifndef DEREFERENCER_H
#define DEREFERENCER_H

#include <detail/is_smart_pointer.hpp>

namespace inact::detail {
    
    template<typename E>
    class Dereferencer {
    public:
        auto& operator()(E const& element) const {
            return dereference_helper(element); 
        }
    private:
        template<typename U, std::enable_if_t< std::is_pointer<U>::value || is_smart_pointer<U>::value, int> = 0>
        auto& dereference_helper(const U& value) const {
            return *value;
        }

        template<typename U, std::enable_if_t< !std::is_pointer<U>::value && !is_smart_pointer<U>::value, int> = 0>
        auto& dereference_helper(const U& value) const {
            return value;
        }
    };

}

#endif /* DEREFERENCER_H */
