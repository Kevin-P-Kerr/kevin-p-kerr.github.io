#include<string.h>

sieve_result *hSieve(ulong n) {
    // calculate the length of the array
    ulong entries = 2*((n/6)+1);
    ulong t = entries;
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
        for(;i<t;i++) {
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
        //fprintf(stdout,"%lu,%lu\n",p,i);
        // mark
        ulong j = i+(2*p);
        for(;j<t;j+=(2*p)) {
            //fprintf(stdout,"marking %lu\n",j);
            mark(j,a);
        }
        int found = 0;
        j = 0;
        if (isFive) {
            // we are looking for a value m, such that
            // 7+6n = pm
            // knowing n will also be useful as it will tell us the index into the array
            if (p == 5) {
                found = 1;
                j = 7;
                //fprintf(stdout,"%lu!!!\n",7+(6*(j/2)));
            }
            else {
                ulong z = (p-7)%6;
                if ((p-7) < 6) {
                    z = 6-(p-7);
                }
                ulong tuple;
                if (z == 0) {
                    //m=1
                    tuple = (p-7)/6;
                    tuple--;
                    j = tuple*2;
                    j++;
                    found = 1;
                }
                else {
                    fprintf(stdout,"here %lu\n",p);
                    ulong diff = 6-z;
                    ulong m = diff*p;
                    m+=p;
                    tuple = (m-7)/6;
                    fprintf(stdout,"\t%lu,%lu,%lu\n",z,m,tuple);
                    j = tuple*2;
                    j++;
                    found = 1;
                }
            }
        }
        else {
            j = 0;
            int found = 0;
            for(;j<t;j+=2) {
                if (!isSet(j,a)) {
                    ulong n = j/2;
                    ulong v = 5+(6*n);
                    if ((v%p) == 0) {
                        //fprintf(stdout,"marking, %lu,%lu\n",j,v);
                        mark(j,a);
                        found = 1;
                        break;
                    }
                }
            }
            if (found) {
                j = j+(2*p);
                for(;j<t;j+=(2*p)) {
                    //fprintf(stdout,"marking: %lu\n",j);
                    mark(j,a);
                }
            }
        }
        if (found) { 
            for(;j<t;j+=(2*p)) {
                fprintf(stdout,"marking: %lu\n",j);
                mark(j,a);
            }
        }
        i++;
    }
    //fprintf(stdout,"Done\n");
    // gather
    prime_record *anchor = malloc(sizeof(prime_record));
    prime_record *pr = anchor;
    pr->next = 0;
    prime_record *secondtolast;
    ulong count = 2;
    for(ulong i=0;i<t;i++) {
        if(!isSet(i,a)) {
            ulong odd = i%2;
            ulong k;
            if (odd==0) {
                k = (5+(6*(i/2)));
            }
            else {
                k = (7+(6*(i/2)));
            }
            //fprintf(stdout,"prime: %lu\n",k);
            pr->value = k;
            prime_record *nxt = malloc(sizeof(prime_record));
            nxt->next = 0;
            pr->next = nxt;
            secondtolast = pr;
            pr=nxt;
            count++;
        }
    }
    secondtolast->next = 0;
    free(pr);
    free(a);
    sieve_result *ret = malloc(sizeof(sieve_result));
    ret->count = count;
    ret->primes = anchor;
    return ret;
}

