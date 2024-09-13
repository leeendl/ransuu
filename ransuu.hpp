#include <array>
#include <time.h>

class ransuu
{
    time_t m{1};
    public:
    short operator[](std::array<short, 2> range) 
    {
        short val = static_cast<short>(time(nullptr) % (++m));
        (val < (-0x7fff - 1)) ? val = (-0x7fff - 1) : (0x7fff < val) ? val = 0x7fff : val;
        return val % (range.back() - range.front() + 1) + range.front();
    }
};