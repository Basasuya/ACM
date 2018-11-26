#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int a[N];
ll suf[N];
ll Mul[N];
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll C(int x, int y) {
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}
int main() {
    int n;
    Mul[1] = 1; Mul[0] = 1;
    for(int i = 2; i < N; ++i) {
        Mul[i] = 1ll* Mul[i-1] * i % MOD;
    }
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        suf[n + 1] = 0;
        for(int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i];
        // for(int i = 1; i <= n; ++i) printf("%lld ", suf[i]); printf("\n");
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = (ans + a[i]) % MOD;
            ans = (ans + suf[i + 1] * 2 % MOD * Pow(i + 1, MOD - 2) % MOD) % MOD;
        }
        // ans = ans * Pow(Mul[n], MOD - 2) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
} 