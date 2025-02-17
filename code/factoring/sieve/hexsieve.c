#include <string.h>
// given an index into the sieve, what is the value associated with it?
ulong calcValue(ulong i) {
    ulong reps = i/2;
    ulong mod = i%2;
    ulong ret = 6*reps;
    return mod==0?7+ret:5+ret;
}
prime_record *hexSieve(ulong n) {
    //TODO: calculate more precisely the length of the array
    ulong t = (n/2)-1; // the number of entries in the array
    // calculate the len of the bit array in ulongs
    ulong len = (t/64)+1;
    // initialize the bit array
    ulong *a = malloc(sizeof(ulong)*len);
    memset(a,0,sizeof(ulong)*len);

    ulong limit = closestSqrRt(n);
    // mark the sieve
    ulong i = 0;
    // track the current prime
    ulong p = 0;
    // track the index of the latest prime
    ulong j = 0;
    while (p<=limit) {
       // find the next prime
       for(;j<t;j++) {
           if (!isSet(j,a)) {
               p = calcValue(j);
               break;
           }
       }
       //mark with the prime, and its powers
       ulong power = 1;
       ulong m = 6*p;
       for(ulong d = upow(p,power);d<=limit;d=upow(p,++power)) {
           for(ulong mm = d+m;mm<t;mm+=m) {
               mark(mm,a);
           }
       }
       // increment j to begin finding the next prime
       j++;
    }
    // gather
    prime_record *anchor = malloc(sizeof(prime_record));
    prime_record *pr = anchor;
    pr->next = 0;
    prime_record *secondtolast;
    for(ulong i=0;i<t;i++) {
        if(!isSet(i,a)) {
            pr->value = calcValue(i);
            prime_record *nxt = malloc(sizeof(prime_record));
            nxt->next = 0;
            pr->next = nxt;
            secondtolast = pr;
            pr=nxt;
        }
    }
    secondtolast->next =0;
    free(pr);
    free(a);
    return anchor;
}
