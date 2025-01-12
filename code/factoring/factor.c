#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include "factor.h"
#include "sieve/oddsieve.c"
#include "primality/mr.c"
#include "sieve/sfactor.c"
#include "util/abs.c"
#include "util/geo.c"
#include "bits/bitmanip.c"
#include "squares/fsquare.c"

ulong total = 0;
int slowest = 0;
ulong slowest_c = 0;
ulong slowest_f = 0;

static void signal_handler(int);
static void cleanup(void);
void init_signals(void);
void panic(const char *, ...);

struct sigaction sigact;

void init_signals(void){
    sigact.sa_handler = signal_handler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigaction(SIGINT, &sigact, (struct sigaction *)NULL);
    sigaction(SIGKILL, &sigact, (struct sigaction *)NULL);
    sigaction(SIGTERM, &sigact, (struct sigaction *)NULL);
}

static void signal_handler(int sig){
    if (sig == SIGINT || sig == SIGTERM || sig == SIGKILL) panic("Caught signal for Ctrl+C\n");
}

void panic(const char *fmt, ...){
    fprintf(stdout,fmt);
    fprintf(stdout,"total:%lu\nslowest %lu, %lu [%dms]\n",total,slowest_c,slowest_f,slowest);
    exit(-1);
}

void cleanup(void){
    sigemptyset(&sigact.sa_mask);
    /* Do any cleaning up chores here */
}

void info(ulong n, ulong f) {
    ulong ff = n/f;
    ulong mid = (f+ff)/2;
    ulong d = abs_diff(ff,f)/2;
    ulong z = n%mid;
    ulong zz = n%d;
    fprintf(stdout,"%lu, %lu, %lu, %lu, %lu\n",n,mid,d,z,zz);
}

void factor(ulong n, prime_record *pr) {
    clock_t start,diff;
    start = clock();
    ulong y = sfactor(n,pr);
    if (y == 0) {
        fprintf(stdout,"%lu, %lu [%dms]\n",n,y,-1);
        panic("^^^^bad bad bad\n");
    }
    diff = clock()-start;
    int ms = diff*1000 / CLOCKS_PER_SEC;
    info(n,y);
    //fprintf(stdout,"%lu, %lu [%dms]\n",n,y,ms);
    if (ms > slowest) {
        slowest = ms;
        slowest_c = n;
        slowest_f = y;
    }
    total++;
}

int main(int argc, char** argv) {
    init_signals();
    prime_record *r = oddSieve(60000000);
    for(ulong i=3;i<2000;i+=2) {
        if (is_prime(i) || isSqr(i)) {
            continue;
        }
        factor(i,r);
    }
}

/*
int main(int argc, char **argv) {
    init_signals();
    ulong i = ULONG_MAX-4000000;
    ulong l = ULONG_MAX-i;
    // 4288415423
    //prime_record *r  = sieve(4313111743*2);
    prime_record *r = oddSieve(60000000);
    i = 3;
    l = 100000;
    for(;i<l;i+=2) {
        if (is_prime(i)) {
            //fprintf(stdout,"%lu, %lu\n",i,1);
            continue;
        }
        factor(i,r);
    }
   // panic("hhh");
}
*/
