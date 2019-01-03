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
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

ll dp[5005][55][2];
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}
int main() {
    int T;
    ll divide5 = Pow(5, MOD - 2);
    ll divide21 = Pow(21, MOD - 2);

    scanf("%d", &T);
    while(T --) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        memset(dp, 0, sizeof(dp));

        dp[1][1][0] = 5; dp[1][1][1] = 21;
        for(int i = 2; i <= n; ++i) {
            ll sum0 = 0; ll sum1 = 0;
            for(int j = 1; j <= a; ++j) sum0 = (sum0 + dp[i - 1][j][0]) % MOD; 
            for(int j = 1; j <= b; ++j) sum1 = (sum1 + dp[i - 1][j][1]) % MOD; 

            for(int j = 2; j <= a; ++j) {
                dp[i][j][0] = dp[i - 1][j - 1][0] * 5 % MOD;
            }
            dp[i][1][0] = sum1 * 5 % MOD;
            
            for(int j = 2; j <= b; ++j) {
                dp[i][j][1] = dp[i - 1][j - 1][1] * 21 % MOD;
            }
            dp[i][1][1] = sum0 * 21 % MOD;
        }

        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= a; ++j) {
                ans = (ans + dp[i][j][0]) % MOD;
            }
            for(int j = 1; j <= b; ++j) {
                ans = (ans + dp[i][j][1]) % MOD;
            }
        }

        printf("%lld\n", ans); 
    }
    return 0;
}