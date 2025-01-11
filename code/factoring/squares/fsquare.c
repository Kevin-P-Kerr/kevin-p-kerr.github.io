ulong semifactor(ulong n) {
    for(ulong i=1;i<n;i++) {
        ulong z = n+(i*i);
        ulong s = closestSqrRt(z);
        if (s*s == z) {
            if(n%(s+i) !=0) {
                fprintf(stdout,"%lu,%lu\n",s,i);
                return 0;
            }
            return i;
        }
    }
    return 1;
}
