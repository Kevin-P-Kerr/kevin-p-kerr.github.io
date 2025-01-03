#include "../factor.h"

ulong isSqr(ulong n) {
    ulong j = getStart(n);
    ulong l = 2;
    ulong ll = j;
    
    while(l<=ll) {
        if (ll-l <= 1) {
            return 0;
        }
        ulong z = (((ll-l)/2)+l);
        ulong t = z*z;
        if (t == n) {
            return z;
        }
        if (t > n) {
            ll = z;
        }
        else {
            l = z;
        }
    }
    return 0;
}

ulong closestSqrRt(ulong n) {
    ulong j = getStart(n);
    ulong l = 2;
    ulong ll = j;
    
    while(l<=ll) {
        if (ll-l <= 1) {
            return ll;
        }
        ulong z = (((ll-l)/2)+l);
        ulong t = z*z;
        if (t == n) {
            return z;
        }
        if (t > n) {
            ll = z;
        }
        else {
            l = z;
        }
    }
    return 0;
}
