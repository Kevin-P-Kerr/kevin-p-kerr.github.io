#include<string.h>

prime_record *hSieve(ulong n) {
    // calculate the length of the array
    ulong entries = 2*((n/6)+1);
    ulong len = (entries/64)+1;
    // instantiate the array
    ulong *a = malloc(sizeof(ulong)*len);
    memset(a,0,sizeof(ulong)*len);
    ulong limit = closestSqrRt(n);
    //mark the array
    // the current prime
    ulong p = 1;
    // current index into the array
    ulong i = 0;
    while (p<=limit) {
        //find the next prime
        ulong isFive = 0;
        for(;i<len;i++) {
            if(!isSet(i,a)) {
                ulong n = i/2;
                if(i%2==0) {
                    // 5+6*n
                    p = 5+(6*n);
                    isFive = 1;
                }
                else {
                    p = 7+(6*n);
                }
                break;
            }
        }
        // mark
        ulong j = i+(2*p);
        for(;j<len;j+=(2*p)) {
            mark(j,a);
        }
        if (isFive) {
            j = 1;
            for(;j<len;j++) {
                if (!isSet(j,a)) {
                    ulong n = j/2;
                    if (((7+(6*n))%p) == 0) {
                        mark(j,a);
                        break;
                    }
                }
            }
            ulong j = i+(2*p);
            for(;j<len;j+=(2*p)) {
                mark(j,a);
            }
        }
        i++;
    }
    // gather
    prime_record *anchor = malloc(sizeof(prime_record));
    prime_record *pr = anchor;
    pr->next = 0;
    prime_record *secondtolast;
    for(ulong i=0;i<len;i++) {
        if(!isSet(i,a)) {
            ulong odd = i%2;
            ulong k;
            if (odd==0) {
                k = (5+(6*(i/2)));
            }
            else {
                k = (7+(6*(i/2)));
            }

            pr->value = k;
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

