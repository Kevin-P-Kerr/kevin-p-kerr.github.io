#include "../factor.h"

void mark(ulong n, ulong *a) {
    ulong index = n/64; 
    ulong b = n-(64*index);
    ulong mask = a[index];
    mask = mask | ((ulong)1<<b);
    a[index] = mask;
}

int isSet(ulong n, ulong *a) {
    ulong index = n/64; 
    ulong b = n-(64*index);
    ulong mask = a[index];
    if ((mask>>b)&(ulong)1) {
        return 1;
    }
    return 0;
}
