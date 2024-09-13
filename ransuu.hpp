#include <array>
#include <time.h>
#include <limits.h>

class ransuu
{
    time_t m{1};
    public:
    short operator[](std::array<short, 2> range) 
    {
        short val = static_cast<short>(time(nullptr) % (++m));
        (val < SHRT_MIN) ? val = SHRT_MIN : (SHRT_MAX < val) ? val = SHRT_MAX : val;
        return val % range.back() + range.front();
    }
};