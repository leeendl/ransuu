#include <pthread_time.h>

#define ll_max 9223372036854775807ll
#define ll_min -ll_max+1

#if __cplusplus == 201103L
    #include <initializer_list>
    template<typename T> 
        using range = std::initializer_list<T>;
#elif __cplusplus > 201103L
// @param front, back
template<typename T>
struct range
{
    T front{}, back{};
};
#endif

class ransuu
{
public:
    // @param _range provide a min, max range of numbers e.g. {0, 100}
    template<typename T = long long>
        T operator[](range<T> _range) 
        {
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            long long val = ts.tv_nsec ^ ( (3 << 8) | (ts.tv_nsec >> 5) );
            (val < ll_min) ? val = ll_min : 
            (ll_max < val) ? val = ll_max : val;
            #if __cplusplus == 201103L
                return static_cast<T>( val % (*(_range.begin() + 1) - *_range.begin() + 1) + *_range.begin() );
            #elif __cplusplus > 201103L
                return static_cast<T>( val % (++_range.back - _range.front) + _range.front );
            #endif
        };
};

#undef ll_max
#undef ll_min