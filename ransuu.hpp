#include <ctime>

#define ll_max 9223372036854775807ll
#define ll_min ll_max*(-1)

#if __cplusplus == 201103L
    #include <initializer_list>
    template<typename T> 
        using range = std::initializer_list<T>;
#elif __cplusplus > 201103L
// @param front, back
template<typename T>
struct range
{
    long long front{}, back{};
};
#endif

class ransuu
{
    unsigned char m{0};
public:
    // @param _range provide a min, max range of numbers e.g. {0, 100}
    template<typename T = long long>
        T operator[](range<T> _range) 
        {
            std::time_t t = std::time({});
            long long val = (std::localtime(&t)->tm_sec * 1000000ll) ^ ((++m << 8) & ll_max);
            (val < ll_min + 1) ? 
                val = ll_min + 1 : 
            (ll_max < val) ? 
                val = ll_max : val;
            #if __cplusplus == 201103L
                return static_cast<T>( val % (*(_range.begin() + 1) - *_range.begin()) + *_range.begin() );
            #elif __cplusplus > 201103L
                return static_cast<T>( val % (_range.back - _range.front) + _range.front );
            #endif
        };
};

#undef ll_max
#undef ll_min