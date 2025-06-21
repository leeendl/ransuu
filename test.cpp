#include "include/ransuu.hpp"
#include <stdio.h>

int main()
{
    ransuu ransuu{};
    for (unsigned char i = 0; i < 50; ++i)
        printf("%d\n", ransuu[{0, 100}]);


    return 0;
}