#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 1e5 + 5;

int M[N];
int t[N];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &M[i]);
        }
        for (int i = n - 1, cur = 0; i >= 0; --i) {
            cur = std::max(0, cur - 1);
            cur = std::max(M[i] + 1, cur);
            t[i] = cur;
        }
        long long ans = 0;
        for (int i = 0, cur = 0; i < n; ++i) {
            cur = std::max(cur, t[i]);
            ans += cur;
            ans -= M[i] + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}