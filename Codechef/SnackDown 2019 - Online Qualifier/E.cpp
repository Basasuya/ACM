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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int S[N];
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
ll Cal(int x) {
    assert(x % 2 == 0 && x > 0);
    return Mul[x] * Pow(Mul[x / 2], MOD-2) % MOD * Pow(Pow(2, x/2), MOD-2)% MOD;
}
ll solve(int x, int pre) {
    // printf("%d %d\n", x, pre);
    ll ans = 1;
    if(pre) {
        ans = ans * x % MOD;
        x --;
    }

    if(x % 2) {
        ans = ans * x % MOD;
        x --; 
    }
    if(x) ans = ans * Cal(x) % MOD;
    return ans;
}
int main() {
    int T;
    scanf("%d", &T);
    Mul[1] = 1; Mul[0] = 1;
    for(int i = 2; i < N; ++i) {
        Mul[i] = 1ll* Mul[i-1] * i % MOD;
    }
    while(T --) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &S[i]);
        sort(S + 1, S + n + 1);
        S[n + 1] = INF;
        int tmp = 0; int pre = 0;
        ll ans = 1;
        for(int i = 2; i <= n + 1; ++i) {
            tmp ++;
            if(S[i] != S[i-1]) {
                ans = (ans * solve(tmp, pre)) % MOD;
                pre = (tmp + pre) % 2;
                tmp = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*


2
4
1 7 3 8
4
2 3 2 2

*/