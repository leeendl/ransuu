#include <time.h>

// @param front, back
struct shorts
{
    short front{};
    short back{};
};

// @param operator[] provide range using shorts struct
class ransuu
{
    unsigned char m{1};
public:
    short operator[](shorts range) 
    {
        short val = static_cast<short>(_time64(nullptr) % (++m));
        (val < (-0x7fff - 1)) ? val = (-0x7fff - 1) : (0x7fff < val) ? val = 0x7fff : val;
        return val % (range.back - range.front + 1) + range.front;
    }
};