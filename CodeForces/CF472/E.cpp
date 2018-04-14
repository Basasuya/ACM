#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
const int N = 1e5 + 5;

struct fraction {
    long long num, deno;
    template <typename T>
    static inline T gcd(const T a, const T b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    fraction() {}
    inline void simplify() {
        if (deno < 0) {
            num *= -1;
            deno *= -1;
        }
        long long g = gcd(num < 0 ? -num : num, deno);
        num /= g;
        deno /= g;
    }
    fraction(long long _num, long long _deno) : num(_num), deno(_deno) { simplify(); }
    inline bool operator<(const fraction& rhs) const { return num * rhs.deno < deno * rhs.num; }
    inline bool operator!=(const fraction& rhs) const { return num * rhs.deno != deno * rhs.num; }
};
std::pair<fraction, fraction> T[N];
std::pair<fraction, int> D[N];
int p[N];
int X[N], V[N];

int bitTree[N];
void add(int pos, int num) {
    for (int i = ++pos; i < N; i += (i & -i)) {
        bitTree[i] += num;
    }
}
int sum(int pos) {
    int result = 0;
    for (int i = ++pos; i; i -= (i & -i)) {
        result += bitTree[i];
    }
    return result;
}

int main() {
    int n, w;
    while (~scanf("%d %d", &n, &w)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &X[i], &V[i]);
        }
        for (int i = 0; i < n; ++i) {
            long long v1 = V[i] - w;
            long long v2 = V[i] + w;
            T[i] = {fraction(-X[i], v1), fraction(-X[i], v2)};
        }

        for (int i = 0; i < n; ++i) {
            T[i].second.num *= -1;
        }
        std::sort(T, T + n);  //-w increase and w descend
        for (int i = 0; i < n; ++i) {
            T[i].second.num *= -1;
        }
        for (int i = 0; i < n; ++i) {
            D[i] = {T[i].second, i};
        }
        std::sort(D, D + n);
        for (int i = 0, rk = -1; i < n; ++i) {
            if ((i == 0) || D[i].first != D[i - 1].first)
                ++rk;
            p[D[i].second] = rk;
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += sum(N - 1) - sum(p[i] - 1);
            add(p[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}