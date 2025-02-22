typedef struct composite_record {
    ulong value;
    struct composite_record *next;
} composite_record;

composite_record *add(ulong i, composite_record *currentcomp) {
    //fprintf(stdout, "adding %lu\n",i);
    ulong v = currentcomp->value;
    v = v*i;
    if (v < currentcomp->value || v>8223372036854775807) {
        composite_record *cr = malloc(sizeof(composite_record));
        cr->value = i;
        cr->next = 0;
        currentcomp->next = cr;
        currentcomp = cr;;
        //fprintf(stdout, "new comp p %lu\n",i);
    }
    else {
        //fprintf(stdout, "new comp %lu\n",v);
        currentcomp->value = v;
    }
    return currentcomp;
}


prime_record *vs(ulong n) {
    composite_record *cr = malloc(sizeof(composite_record));
    cr->value=3;
    cr->next = 0;
    composite_record *currentcom = cr;
    prime_record *anchor = malloc(sizeof(prime_record));
    anchor->value = 3;
    anchor->next = 0;
    prime_record *current = anchor;
    ulong i = 5;
    for(;i<=n;i+=2) {
        composite_record *ccr = cr;
        int isPrime = 1;
        for(;ccr != 0;ccr=ccr->next) {
            if(gcd(ccr->value,i) > 1) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime==1) {
            prime_record *pr = malloc(sizeof(prime_record));
            pr->value = i;
            pr->next = 0;
            current->next = pr;
            current = pr;
            currentcom = add(i,currentcom);
        }
    }
    return anchor;
}




