#include "../factor.h"

ulong factorTD(ulong x) {
    ulong z = 3;
    while(x%z >0) {
        z+=2;
        if (z>=x) {
            return 1;
        }
    }
    return z;
}

