#ifndef IS_SMART_POINTER
#define IS_SMART_POINTER

#include <type_traits>
#include <memory>

namespace inact::detail {

    template<typename T>
    struct is_shared_pointer : std::false_type {};

    template<typename T>
    struct is_shared_pointer< std::shared_ptr<T> > : std::true_type {};

    template<typename T>
    struct is_unique_pointer : std::false_type {};

    template<typename T>
    struct is_unique_pointer< std::unique_ptr<T> > : std::true_type{};

    template<typename T>
    struct is_weak_pointer : std::false_type {};

    template<typename T>
    struct is_weak_pointer< std::weak_ptr<T> > : std::true_type {};

    template<typename T, typename T2 = void>
    struct is_smart_pointer : std::false_type {};

    template<typename T>
    struct is_smart_pointer<T, std::enable_if_t< is_shared_pointer<T>::value ||
                                             is_unique_pointer<T>::value ||
                                             is_weak_pointer<T>::value >> : std::true_type {};

}
#endif /* ifndef IS_SMART_POINTER */
