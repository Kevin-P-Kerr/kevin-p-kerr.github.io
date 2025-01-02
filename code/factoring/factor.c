#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include "trial_division/trialdivision.c"
#include "primality/mr.c"

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
    fprintf(stdout,"total:%lu\nslowest %lu, %lu [%dms]\n",total,slowest_c,slowest_f,slowest);
    exit(-1);
}

void cleanup(void){
    sigemptyset(&sigact.sa_mask);
    /* Do any cleaning up chores here */
}

void factor(ulong n) {
    clock_t start,diff;
    start = clock();
    ulong y = factorTD(n);
    diff = clock()-start;
    int ms = diff*1000 / CLOCKS_PER_SEC;
    fprintf(stdout,"%lu, %lu [%dms]\n",n,y,ms);
    if (ms > slowest) {
        slowest = ms;
        slowest_c = n;
        slowest_f = y;
    }
    total++;
}

int main(int argc, char **argv) {
    init_signals();
    ulong i = ULONG_MAX-2000000;
    ulong l = ULONG_MAX-i;
    for(;l>0;i+=2,l-=2) {
        if (is_prime(i)) {
            continue;
        }
        factor(i);
    }
    panic("hhh");
}
