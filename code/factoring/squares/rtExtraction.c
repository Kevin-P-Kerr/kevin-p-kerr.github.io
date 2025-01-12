rat *rt(ulong n) {
    ulong l = closestSqrRt(ULONG_MAX);
    while (l>1) {
        ulong s = l*l;
        ulong f = s/n;
        ulong z = 5;
        for(;z>=0;z--) {
            if(isSqr(f-z)) {
                rat *r = malloc(sizeof(rat));
                r->num = f-z;
                r->denom = s;
                return r;
            }
        }
        l--;
    }
    return 0;
}
