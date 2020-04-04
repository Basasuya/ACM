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
using namespace std;
// const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

ll Mul[M];
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
    if(x == y) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out2", "w", stdout);
    int T;
    scanf("%d", &T);
    Mul[1] = 1;
    Mul[0] = 1;
    for(int i = 2; i < M; ++i) {
        Mul[i] = Mul[i-1] * i % MOD;
    }
    for(int _ = 1; _ <= T; ++_) {
        int n, m;
        scanf("%d %d", &n, &m);
        ll ans = Mul[2*n];
        int init = 2*n; ll mul2 = 1;
        for(int i = 1; i <= m; ++i) {
            init --;
            mul2 = mul2 * 2 % MOD;
            ll tmp = mul2 * Mul[init] % MOD * C(m, i) % MOD;
            ans = (ans + ( (i % 2) ? -tmp : tmp) + MOD) % MOD;
        }

        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}