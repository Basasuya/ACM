long long mlprime[6] = {2, 3, 5, 233, 331};

long long qmul(long long x, long long y, long long mod) {
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) % mod;
}

long long qpow(long long a, long long n, long long mod) {
    long long ret = 1;
    while (n) {
        if (n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}

bool Miller_Rabin(long long p) {
    if (p < 2) return 0;
    if (p != 2 && p % 2 == 0) return 0;
    long long s = p - 1;
    while (! (s & 1)) s >>= 1;
    for (int i = 0; i < 5; ++i) {
        if (p == mlprime[i]) return 1;
        long long t = s, m = qpow(mlprime[i], s, p);
        while (t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if (m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}