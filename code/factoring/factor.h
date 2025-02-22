typedef unsigned long ulong;

typedef struct prime_record {
    ulong value;
    struct prime_record *next;
} prime_record;

typedef struct rat {
    ulong num;
    ulong denom;
} rat;

ulong closestSqrRt(ulong n);

ulong isSqr(ulong n);

ulong abs_diff(ulong x, ulong y);

ulong sfactor(ulong n, prime_record *pr);

prime_record *hexSieve(ulong n);

prime_record *oddSieve(ulong n);

prime_record *sieve(ulong n);

void mark(ulong n, ulong *a);

int isSet(ulong n, ulong *a);

int is_prime(ulong n);

ulong gcd(ulong a, ulong b);

ulong upow(ulong b, ulong p);
prime_record *vs(ulong n);
