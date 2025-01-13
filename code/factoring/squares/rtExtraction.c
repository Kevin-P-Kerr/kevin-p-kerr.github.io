rat *rt(ulong n) {
    ulong l = closestSqrRt(ULONG_MAX);
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

void printAll(ulong n, ulong l) {
    while (l>2) {
        ulong s = l*l;
        // a^2 = nb^2
        ulong t = s/n;
        if(isSqr(t) || isSqr(t-1)) {
            fprintf(stdout,"%lu/%lu\n",l,closestSqrRt(t));
        }
        l--;
    }
}
