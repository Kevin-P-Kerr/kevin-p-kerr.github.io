typedef struct composite_record {
    ulong comp;
    composite_record *next;
} composite_record;

void add(ulong i, composite_record *currentcomp) {
    ulong v = currentcomp->value;
    v = v*i;
    if (v < currentcomp->value) {
        composite_record *cr = malloc(sizeof(composite_record));
        cr->value = i;
        cr->next = 0;
        currentcomp->next = cr;
        currentcomp = cr;;
    }
    else {
        currentcomp->value = v;
    }
    return currentcomp;
}


prime_record *vs(ulong n) {
    composite_record *cr = malloc(sizeof(composite_record));
    cr->comp=2;
    cr->next = 0;
    composite_record *currentcom = cr;
    prime_record *anchor = malloc(sizeof(prime_record));
    anchor->value = 2;
    anchor->next = 0;
    prime_record *current = anchor;
    ulong i = 3;
    for(;i<=n;i++) {
        composite_record *ccr = cr;
        int isPrime = 1;
        for(;ccr != 0;ccr=ccr->next) {
            if(gcd(ccr->value,i)) {
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




