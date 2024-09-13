#include <array>
#include <time.h>
#include <bits\stl_algo.h>

class ransuu
{
    time_t m{1};
    public:
    short operator[](std::array<short, 2> range) 
    {
        return std::clamp<short>(static_cast<short>(time(nullptr) % (++m)), 0, 32767) % range.back() + range.front();
    }
};