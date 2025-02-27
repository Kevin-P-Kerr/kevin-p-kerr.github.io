typedef unsigned long ulong;

typedef struct prime_record {
    ulong value;
    struct prime_record *next;
} prime_record;

typedef struct rat {
    ulong num;
    ulong denom;
} rat;

typedef struct sr {
    prime_record *primes;
    ulong count;
} sieve_result;

ulong closestSqrRt(ulong n);

ulong isSqr(ulong n);

ulong abs_diff(ulong x, ulong y);

ulong sfactor(ulong n, prime_record *pr);

sieve_result *hexSieve(ulong n);

sieve_result *oddSieve(ulong n);

sieve_result *sieve(ulong n);

void mark(ulong n, ulong *a);

int isSet(ulong n, ulong *a);

int is_prime(ulong n);

ulong gcd(ulong a, ulong b);

ulong upow(ulong b, ulong p);
sieve_result *vs(ulong n);
