#include "../factor.h"

ulong closestSqr(ulong n) {
    ulong a = 2;
    ulong b = n;
    ulong z = n/2;
    while (1) {
        if ((b-a) == 1) {
            return z;
        }
        ulong t = z*z;
        if (t == n) {
            return z;
        }
        if (t > n) {
            b = z;
        }
        else {
            a = z;
        }
        z = (a+b)/2;
    }
}

ulong isSqr(ulong n) {
    ulong z = closestSqr(n);
    if (z*z==n) {return 1;}
    return 0;
}
