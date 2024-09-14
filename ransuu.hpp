#include <time.h>

// @param front, back
struct range
{
    long long front{}, back{};
};

// @param operator[] provide range using range struct
class ransuu
{
    unsigned char m{0};
public:
    short operator[](range r) 
    {
        long long val = (_time64({}) ^ (++m << 4)) & 9223372036854775807ll-1;
        (val < -9223372036854775807ll-1) ? val = -9223372036854775807ll-1 : (9223372036854775807ll < val) ? val = 9223372036854775807ll : val;
        return val % (r.back - r.front + 1) + r.front;
    }
};