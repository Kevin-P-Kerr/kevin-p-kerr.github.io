#include <stdlib.h>
#include <string.h>
#include "../util/geo.c"
#include "../bits/bitmanip.c"
#include "sieve.h"
#include <stdio.h>


void p(prime_record *pr) {
    for(;pr != 0;pr=pr->next) {
        fprintf(stdout,"%lu\n",pr->value);
    }
}

prime_record *sieve(ulong n) {
    ulong len = 1+(n/64);
    ulong *a = malloc(sizeof(ulong)*len);
    memset(a,0,sizeof(ulong)*len);
    ulong p = 2;
    ulong limit = closestSqrRt(n);
    while (p<=limit) {
        // mark
        for(ulong i=2*p;i<n;i+=p) {
            mark(i,a);
        }
        // get next prime
        for(ulong i =p+1;i<n;i++) {
            if(!isSet(i,a)) {
                p = i;
                break;
            }
        }
    }
    // get primes
    prime_record *record = malloc(sizeof(prime_record));
    record->value = 2;
    record->next = 0;
    prime_record *anchor = record;
    for(ulong i=3;i<n;i++) {
        if(!isSet(i,a)) {
            prime_record *n = malloc(sizeof(prime_record));
            n->value = i;
            n->next = 0;
            record->next = n;
            record = n;
        }
    }
    free(a);
    return anchor;
}