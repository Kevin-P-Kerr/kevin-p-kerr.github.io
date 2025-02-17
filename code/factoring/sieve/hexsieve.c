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
       ulong pow = 1;

    }
}
