#include "../factor.h"
#include "sieve.h"

ulong sfactor(ulong n, prime_record *pr) {
    for(;pr != 0;pr=pr->next) {
        ulong v = pr->value;
        if (n%v == 0) {
            return v;
        }
    }
    return 0;
}


