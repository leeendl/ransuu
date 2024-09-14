#include "ransuu.hpp"
#include <stdio.h>

int main()
{
    ransuu r{};
    for (unsigned char i = 0; i < 255; ++i) // @note per ransuu class can only perform 255 random numbers.
        printf("%d\n", r[range{0, 20}]);
        
    return 0;
}