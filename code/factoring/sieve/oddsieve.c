#include <stdlib.h>
#include <string.h>
#include "../util/geo.c"
#include "../bits/bitmanip.c"
#include "sieve.h"
#include <stdio.h>

prime_record *oddSieve(ulong n) {
    ulong t = (n/2)+1; // the number of entries in the array
    // calculate the len of the bit array in ulongs
    ulong len = (t/64)+1;
    // initialize the bit array
    ulong *a = malloc(sizeof(ulong)*len);
    memset(a,0,sizeof(ulong)*len);
    // a[0]=3,a[1]=5
    // i.e. a[n] = 2(n+1)+1 = 2n+3
    // mark the array
    ulong j = 0; // track the latest prime
    ulong limit = closestSqrRt(n);
    ulong p = 0; // the current prime with which we mark
    while(p<=limit) {
        // find the next prime
        for(;j<t;j++) {
            if (!isSet(j,a)) {
                p = (2*j)+3;
                break;
            }
        }
        // mark with the prime
        for(ulong i=j+p;i<t;i+=p) {
            fprintf(stdout,"mark!\n");
            mark(i,a);
        }
        // increment j to begin finding the next prime
        j++;
    }
    // gather
    prime_record *anchor = malloc(sizeof(prime_record));
    prime_record *pr = anchor;
    pr->next = 0;
    for(ulong i=0;i<t;i++) {
        if(!isSet(i,a)) {
            fprintf(stdout,"hit!\n");
            pr->value = (2*i)+3;
            prime_record *nxt = malloc(sizeof(prime_record));
            nxt->next = 0;
            pr->next = nxt;
            pr=nxt;
        }
    }
    free(a);
    return anchor;
}
