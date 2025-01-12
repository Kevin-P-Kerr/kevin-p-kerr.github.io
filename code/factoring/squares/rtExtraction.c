rat *rt(ulong n) {
    ulong l = closestSqrRt(900000000000000);
    //ulong l = closestSqrRt(500);
    while (l>2) {
        ulong s = l*l;
        // a^2 = nb^2
        ulong t = s/n;
        if(isSqr(t) || isSqr(t-1)) {
            rat *r = malloc(sizeof(rat));
            r->num = l;
            r->denom = closestSqrRt(t);
            return r;
        }
        l--;
    }
    return 0;
}
