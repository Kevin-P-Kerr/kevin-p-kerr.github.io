void p(prime_record *pr) {
    for(;pr != 0;pr=pr->next) {
        fprintf(stdout,"%lu\n",pr->value);
    }
}
