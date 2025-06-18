#include <pthread_time.h>

#define l_max 2147483647l
#define l_min -l_max+1

#if __cplusplus == 201103L
    #include <initializer_list>
    template<typename T> 
        using range = std::initializer_list<T>;
#elif __cplusplus > 201103L
template<typename T>
struct range
{
    T front{}, back{};
};
#endif

class ransuu
{
public:
    // @param _range min, max range of numbers e.g. {0, 100}
    template<typename T = long>
        T operator[](range<T> _range) 
        {
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            long val = ts.tv_nsec ^ ( 123 | (ts.tv_nsec >> 5) );
            (val < l_min) ? val = l_min : 
            (l_max < val) ? val = l_max : val;
            #if __cplusplus == 201103L
                return static_cast<T>( val % (*(_range.begin() + 1) - *_range.begin() + 1) + *_range.begin() );
            #elif __cplusplus > 201103L
                return static_cast<T>( val % (++_range.back - _range.front) + _range.front );
            #endif
        };
};

#undef l_max
#undef l_min