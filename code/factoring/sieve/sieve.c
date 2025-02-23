#include <string.h>
sieve_result *sieve(ulong n) {
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
        //fprintf(stdout,"%lu/%lu\n",p,limit);
    }
    // get primes
    prime_record *record = malloc(sizeof(prime_record));
    record->value = 2;
    record->next = 0;
    prime_record *anchor = record;
    ulong count = 1;
    for(ulong i=3;i<n;i++) {
        if(!isSet(i,a)) {
            prime_record *n = malloc(sizeof(prime_record));
            n->value = i;
            n->next = 0;
            record->next = n;
            record = n;
            count++;
        }
    }
    free(a);
    sieve_result *ret = malloc(sizeof(sieve_result));
    ret->count = count;
    ret->primes = anchor;
    return ret;
}
