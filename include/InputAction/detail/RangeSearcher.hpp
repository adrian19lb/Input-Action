#ifndef RANGE_SEARCHER_HPP
#define RANGE_SEARCHER_HPP

#include <utility>

namespace inact::detail {
    
    template<typename T, typename E> 
    class RangeSearcher {
    public:
        /** 
         * Construct a new RangeSearcher.
         *
         * \param predictor Source predictor.
         */
        constexpr RangeSearcher(T predictor)
        : predictor{predictor} {
        }

        ~RangeSearcher() = default;

        /**
         * Move constructor
         */
        RangeSearcher(RangeSearcher&& searcher)
        : predictor{ std::move(searcher.predictor) } {
        
        }
        
        /**
         * Copy constructor
         */
        RangeSearcher(RangeSearcher const& searcher)
        : predictor{searcher.predictor} {
        
        }

        /**
         * Copy assignment operator
         */
        RangeSearcher& operator=(RangeSearcher const& searcher) {
            predictor = searcher.predictor;
            return *this;
        }
        
        /**
         * Move assignment operator
         */
        RangeSearcher& operator=(RangeSearcher&& searcher) {
            predictor = std::move(searcher.predictor);
            return *this;
        }    
        
        /**
         * Overload of call operator ().
         * Find value in given range with optional arguments passed to predictor.
         * If predictor requirements were met, return first encountered value 
         * in given range. Otherwise return last one element.
         * Passed arguments to call operator must be the same type as taken by predictor.
         * \sa predictor.
         *
         * \param[in] first First element in searched range.
         * \param[in] last Last element in searched range.
         * \param[in] optional Paramater pack with optional arguments.
         *
         * \return Found element in range or last one.
         */
        template<typename... Opt>
        E operator()(E first, E last, Opt&&... optional) {
            for (int i = first; i != last; ++i) {
                auto value = static_cast<E>(i);
                if ( predictor( std::forward<Opt>(optional)..., value ) ) {
                    return value;
                }
            }

            return last;
        }
    private:
        /*************************************//**
        * Member data
        ****************************************/                                         
        T predictor; /**< Predictor for evaluate ability of getting value */
    };

}

#endif /* ifndef RANGE_SEARCHER_HPP */
    
/**
* \class inpt::utils::RangeSearcher
* \brief Template functor class for searching avalible value in specified range.
* \detail 
* inpt:listener::RangeSearcher use functor or wrapped function, lambda expresion
* to predict ability of retriving some value.
* This predictor  
*/
