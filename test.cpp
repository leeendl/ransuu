#include "ransuu.hpp"
#include <stdio.h>

int main()
{
    ransuu r{};
    for (unsigned char i = 0; i < 50; ++i)
        printf("%d\n", r[{0, 100}]);
        
    return 0;
}