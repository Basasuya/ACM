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
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

ll pre[N];
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll solve(int l, int r) {
    // printf("%d %d\n", l, r);
    if(l > r) return 1;
    if(l <= 1) return 0;
    // ll ans = 1;
    // for(int i = l; i <= r; ++i) {
    //     ans = ans * ( (1ll *i *i - i) % MOD ) % MOD;
    // }
    // return ans;
    int tmp = 0;
    if(r >= N) tmp = r, r = N - 1;
    ll tt = 1;
    if(l <= N - 1) {
        tt = pre[r] * Pow(pre[l-1], MOD - 2) % MOD;
        // printf("hhh\n");
    }
    for(int i = max(l, N); i <= tmp; ++i) {
        // printf("xxx\n");
        ++r;
        tt = tt * ( (1ll * i * i - i) % MOD ) % MOD;
    }
    // printf("%lld\n", tt);
    return tt;
}
int main() {
    int T;
    pre[1] = 1;
    pre[2] = 2;
    for(int i = 3; i < N; ++i) pre[i] = pre[i-1] * ( (1ll* i * i - i) %MOD )% MOD;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d %d", &n, &k);
        int l = 1; int r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if( 1ll * (mid + mid + k - 1) * k / 2 <= n) l = mid + 1;
            else r = mid - 1;
        }

        int st = r;
        int lef = n - 1ll * (st + st + k - 1) * k / 2;
        if(st == 0) {
            printf("-1\n");
        } else {
            
            int lpart = k - lef; int rpart = lef;
            assert(lpart > 0);
            int lst = st; int rst = st + lpart + 1;
            ll ans = solve(lst, lst + lpart - 1) * solve(rst, rst + rpart - 1) % MOD;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
/*

1000000000 1000

*/