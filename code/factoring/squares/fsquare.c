ulong semifactor(ulong n) {
    for(ulong i=1;i<n;i++) {
        ulong z = n+(i*i);
        ulong s = closestSqr(z);
        if (s*s == z) {
            if(z%(s+i) !=0) {
                return 0;
            }
            return i;
        }
    }
    return 1;
}
