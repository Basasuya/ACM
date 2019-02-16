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

char s[N];
int buf[60];
ll fac[N];
ll inv[N];
ll dp[N];
ll tempDp[N];
ll ans[60][60];
int find(char x) {
    int tmp;
    if(x >= 'A' && x <= 'Z') tmp = x - 'A' + 26;
    else tmp = x - 'a';
    return tmp;
}
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
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    
    while(~scanf("%s", s)) {
        
        memset(buf, 0, sizeof(buf));
        memset(ans, 0, sizeof(ans));
        memset(dp, 0, sizeof(dp));

        
        int n = strlen(s);
        inv[n] = Pow(fac[n], MOD-2);
        \
        for(int i=n-1;i>=0;i--)inv[i]=(inv[i+1]*1ll*(i+1)) % MOD;
        for(int i = 0, len = strlen(s); i < len; ++i) {
            buf[find(s[i])] ++;
        }

        ll base = fac[n / 2] * fac[n / 2] % MOD;
        for(int i = 0; i < 52; ++i) {
            base = base * inv[buf[i]] % MOD;
        }

        dp[0] = 1;
        for(int i = 0; i < 52; ++i) {
            if(!buf[i]) continue;
            for(int j = n; j >= buf[i]; --j) {
                dp[j] = (dp[j] + dp[j - buf[i]]) % MOD;
            }
        }

        // for(int i = 0; i < 52; ++i) printf("%lld ", dp[i]);


        for(int i = 0; i < 52; ++i) {
            ans[i][i] = dp[n / 2];
        }

        for(int i = 0; i < 52; ++i) {
            if(!buf[i]) continue;
            for(int j = 0; j <= n; ++j) {
                tempDp[j] = dp[j];
            }

            for(int j = buf[i]; j <= n; ++j) {
                tempDp[j] = (tempDp[j] - tempDp[j - buf[i]] + MOD) % MOD;
            }

            for(int j = i + 1; j < 52; ++j) {
                if(!buf[j]) continue;
                for(int k = buf[j]; k <= n; ++k) {
                    tempDp[k] = (tempDp[k] - tempDp[k - buf[j]] + MOD) % MOD;
                }

                ans[i][j] = ans[j][i] = 2 * tempDp[n / 2] % MOD;

                for(int k = n; k >= buf[j]; --k) {
                    tempDp[k] = (tempDp[k] + tempDp[k - buf[j]]) % MOD;
                }
            }
        }

        int q;
        scanf("%d", &q);
        while(q --) {
            int x, y; scanf("%d %d", &x, &y);
            printf("%lld\n", base * ans[find(s[x - 1])][find(s[y - 1])] % MOD);
        }

    }
    return 0;
}
