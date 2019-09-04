#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <deque>

namespace inact::detail {

    template<size_t N, typename T>
    class Buffer {
    public:
        Buffer()
        : CAPACITY(N)
        , values(N) {

        }

        const T& top() {
            return values.front();
        }

        void backup(T&& value) {
            clearIfReachedCapacity();
            values.emplace_front( std::forward<T>(value) );
        }

        void backup(const T& value) {
            clearIfReachedCapacity();
            values.emplace_front(value);
        }

        void clear() {
            values.clear();
        }

    private:
        void clearIfReachedCapacity() {
            if (values.size() == CAPACITY) {
                values.pop_back();
            }
        }
    private:
        std::deque<T> values;
        const size_t CAPACITY;
    };


}

#endif /* ifndef BUFFER_HPP */
