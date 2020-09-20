#include "solution.c"
#include <math.h>

int main()
{
    double x = -100000009000009;
    classify(x);

    for (int i = 0; i < 64; ++i)
    {
        printf("%d", getBit(convertToUint64(x),63-i));
    }

    return 0;
}

