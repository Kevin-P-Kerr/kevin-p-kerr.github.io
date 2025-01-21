int overflow(ulong p, ulong m) {
    if (p%m != 0) {
        return 1;
    }
    return 0;
}
int lte(rat a, rat b) {
    ulong aa = a.num*b.denom;
    ulong bb = b.num*a.denom;
    if(overflow(aa,a.num)||overflow(bb,b.num)) {
        return 0;
    }
    if (aa <= bb) {
        return 1;
    }
    return 0;
}

// determine the closest rational number to a given square root.
rat closestRat(ulong sqr, ulong maxDenom) {
    rat *maxd = malloc(sizeof(rat));
    maxd->num=1;
    maxd->denom=0;
    rat *ret = malloc(sizeof(rat));
    ret->num = 0;
    ret->denom = 0;
    for(ulong n=1;n<=maxDenom;n++) {
        if(n%1000 == 0) {
        fprintf(stdout,"%lu\n",n);
        }
        for(ulong i=n+1;i<=maxDenom;i++) {
            ulong is = i*i;
            ulong ns = n*n;
            if(overflow(is,i) || overflow(ns,n) || overflow(sqr*ns,ns)) {
                fprintf(stdout,"overflow!\n");
                break;
            }
            ulong d = abs_diff(sqr*ns,is);
            rat *rd = malloc(sizeof(rat));
            rd->num=d;
            rd->denom=ns;
            if (lte(*rd,*maxd)) {
                fprintf(stdout,"%lu, %lu, %lu\n",i,n,d);
                ret->num = i;
                ret->denom = n;
                maxd = rd;
            }
        }
    }
    return *ret;
}
