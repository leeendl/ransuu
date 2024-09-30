#include <ctime>

#define ll_max 9223372036854775807ll
#define ll_min ll_max*(-1)

#if __cplusplus <= 201103L
    #include <array>
    using range = std::array<long long, 2>;
#else
// @param front, back
struct range
{
    range(long long front, long long back) : f(front), b(back) {};
    long long front()
    {
        return this->f;
    };
    long long back()
    {
        return this->b;
    };
private:
    long long f{}, b{};
};
#endif

class ransuu
{
    unsigned char m{0};
public:
    // @param _range provide a min, max range of numbers e.g. {0, 100}
    long long operator[](range _range) 
    {
        std::time_t t = std::time({});
        long long val = (std::localtime(&t)->tm_sec * 1000000ll) ^ ((++m << 8) & ll_max);
        (val < ll_min + 1) ? 
            val = ll_min + 1 : 
        (ll_max < val) ? 
            val = ll_max : val;
        return{ val % (_range.back() - _range.front() + 1) + _range.front() };
    };
};