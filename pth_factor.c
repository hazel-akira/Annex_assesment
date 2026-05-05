long pthFactor(long n, long p) {
    long i;
    long small[100000], large[100000];
    long sc = 0, lc = 0;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            small[sc++] = i;

            if (i != n / i) {
                large[lc++] = n / i;
            }
        }
    }

    if (p <= sc) return small[p - 1];

    p -= sc;

    if (p <= lc) return large[lc - p];

    return 0;
}