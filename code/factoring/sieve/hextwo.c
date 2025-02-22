#include<string.h>

prime_record *hSieve(ulong n) {
    // calculate the length of the array
    ulong entries = 2*((n/6)+1);
    ulong len = (entries/64)+1;
    // instantiate the array
    prime_record *a = malloc(sizeof(prime_record)*len);
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
                    ifFive = 1;
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

    }

}
