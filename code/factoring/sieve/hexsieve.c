prime_record *hexSieve(ulong n) {
    //TODO:
    ulong t = (n/2)-1; // the number of entries in the array
    // calculate the len of the bit array in ulongs
    ulong len = (t/64)+1;
    // initialize the bit array
    ulong *a = malloc(sizeof(ulong)*len);
    memset(a,0,sizeof(ulong)*len);
}
