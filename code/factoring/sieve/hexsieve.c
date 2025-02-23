#include <string.h>
int isSevenExpressed(ulong p) {
    return (p%6)==1?1:0;
}

int isFiveExpressed(ulong p) {
    if (p==5) { return 0; }
    return (p%6)==1?0:1;
}


// give a prime in the form 7+6p
// find a multiple of it in the form 5+6n
// 5+6n = qm, where q is the prime
// 6n = qm-5
// so we are looking for a multiple such that, when 5 is subracted from it, we get a multiple of 6
ulong getFiveExpressed(ulong p) {
    ulong m = 2;
    ulong pp = p;
    while ((p-5)%6!=0) {
        p = pp*m;
        m++;
    }
    return p;
}
// given a value, what is its index
ulong translate(ulong v) {
    ulong p = v/6;
    ulong q = v%6;
    if (q == 1) {
        p = p-1;
        return (p*2)+1;
    }
    return p*2;
}
// given an index into the sieve, what is the value associated with it?
ulong calcValue(ulong i) {
    ulong reps = i/2;
    ulong mod = i%2;
    ulong ret = 6*reps;
    return mod==0?5+ret:7+ret;
}
sieve_result *hexSieve(ulong n) {
    while (n%2==0 || n%3==0) {
        n++;
    }
    ulong t = translate(n); // the number of entries in the array
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
       for(ulong d = upow(p,power);d<=n;d=upow(p,++power)) {
           //fprintf(stdout, "here %lu,%lu\n", d,p);
           if (d>p) {
               ulong x = translate(d);
               mark(x,a);
           }
           if (isSevenExpressed(p)) {
               ulong mm = getFiveExpressed(p);
               for(;mm<n;mm+=m) {
                   ulong x = translate(mm);
                   mark(x,a);
               }
           }
           for(ulong mm = d+m;mm<n;mm+=m) {
               ulong x = translate(mm);
               //fprintf(stdout,"mark: %lu,%lu,%lu\n",mm,x,calcValue(x));
               mark(x,a);
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
    ulong count = 2;
    for(ulong i=0;i<t;i++) {
        if(!isSet(i,a)) {
            pr->value = calcValue(i);
            prime_record *nxt = malloc(sizeof(prime_record));
            nxt->next = 0;
            pr->next = nxt;
            secondtolast = pr;
            pr=nxt;
            count++;
        }
    }
    secondtolast->next =0;
    free(pr);
    free(a);
    sieve_result *ret = malloc(sizeof(sieve_result));
    ret->count = count;
    ret->primes = anchor;
    return ret;
}
