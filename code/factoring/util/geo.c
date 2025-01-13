ulong findStart(ulong n) {
    // get the number of leading zeros
    ulong z = __builtin_clzl(n);
    // 00011010 -- 5 are set
    z = 64-z;
    z = z/2;
    ulong j = 1;
    for(;z>0;z--) { j = j+(j*2); }
    return j;
}

int overflows(ulong b, ulong s) {
    if (b==0) {
        return 0;
    }
    ulong z = b*b;
    if (z/b == b) {
        return 0;
    }
    return 1;
}

ulong closestSqrRt(ulong n) {
    // a<=sqrt
    ulong a = 2;
    // b>sqrt
    ulong b = n;
    // z is the candidate
    ulong z = findStart(n);
    b = z+1;
    while (1) {
        if ((b-a) == 1) {
            return a;
        }
        ulong t = z*z;
        if (t == n) {
            return z;
        }
        if (t > n || overflows(z,t)) {
            b = z;
        }
        else {
            a = z;
        }
        z = (a+b)/2;
    }
}

ulong isSqr(ulong n) {
    ulong z = closestSqrRt(n);
    if (z*z==n) {return 1;}
    return 0;
}
