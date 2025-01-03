#include "../factor.h"

//TODO: revisit this
ulong getStart(ulong n) {
    ulong j = 1;
    ulong bits = 1;
    while (j <n && bits<64) {
        j*=2;
        bits++;
    }
    bits=bits/2;
    j = 1;
    while (bits >= 1) {
        j*=2;
        bits--;
    }
    return j;
}

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
