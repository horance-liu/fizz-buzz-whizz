#include "game/Predicate.h"

bool times(int n, int radix)
{
    return n % radix == 0;
}

bool contains(int n, int radix)
{
    auto m = 0;

    while (n>0)
    {
        m = n%10;
        n = n/10;
        if (m==radix) return true;
    }

    return false;
}

bool always_true(int)
{
    return true;
}
