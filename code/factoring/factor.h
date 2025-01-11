typedef unsigned long ulong;

typedef struct prime_record {
    ulong value;
    struct prime_record *next;
} prime_record;

ulong closestSqr(ulong n);

ulong isSqr(ulong n);

ulong abs_diff(ulong x, ulong y);

ulong sfactor(ulong n, prime_record *pr);

prime_record *oddSieve(ulong n);

prime_record *sieve(ulong n);

void mark(ulong n, ulong *a);

int isSet(ulong n, ulong *a);
