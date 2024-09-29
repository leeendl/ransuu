#include <time.h>

#define ll_max 9223372036854775807ll
#define ll_min ll_max*(-1)

// @param front, back
struct range
{
    long long front{}, back{};
};

class ransuu
{
    unsigned char m{0};
public:
    // @param _range provide a min, max range of numbers e.g. {0, 100}
    long long operator[](range _range) 
    {
        time_t t = _time64({});
        long long val = (((localtime(&t)->tm_sec * 1000000ll) ^ (++m << 8))) & ll_max;
        (val < ll_min + 1) ? 
            val = ll_min + 1 : 
        (ll_max < val) ? 
            val = ll_max : val;
        return{ val % (_range.back - _range.front + 1) + _range.front };
    }
};