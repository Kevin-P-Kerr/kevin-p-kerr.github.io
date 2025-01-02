#include <stdio.h>

ulong gcd(ulong a, ulong b) {
    if (a == b) {
        return a;
    }
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a%b;
        }
        else {
            b = b%a;
        }
    }
    return a == 0?b:a;
}

