#include <stdlib.h>
#include <string.h>
#include "../util/geo.c"
#include "../bits/bitmanip.c"
#include "sieve.h"
#include <stdio.h>

prime_record *oddSieve(ulong n) {
    ulong len = ((1+(n/65))/2)+1;
    ulong *a = malloc(sizeof(ulong)*len);
    ulong limit = cloestSqrRt(n);
    // each number in a is 2n+1, starting with n=1
    ulong p =0;
    // mark
    while (p <= limit) {
        ulong i;
        for(i=0;i<len;i++) {
            if(!isSet(i,a)) {
                p = (2*(i+1))+1
                i+=p;
                break;
            }
        }
        for(;i<len;i+=p) {
            mark(i,a);
        }
    }
    //gather primes
    prime_record *anchor = malloc(sizeof(prime_record));
    prime_record *p = anchor; 
    p->next = 0;
    for(ulong i=0;i<len;i++) {
        if (!isSet(i,a)) {
            ulong val = (2*(i+1))+1;
            p->value = p;
            prime_record *nxt = malloc(sizeof(prime_record));
            nxt->next= 0;
            p->next = nxt;
            p = nxt;
        }
    }
    return anchor;
}
