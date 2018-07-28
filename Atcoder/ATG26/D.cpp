#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int MOD = 1e9+7;


int h[N];
int Has[N]; int tot;
ll dp[N][N];

ll Pow(ll x, ll y) {
	if(y <= 0) return 1;
	ll result = 1;
	while(y) {
		if(y & 1)
			result = result * x % MOD;
		y >>= 1;
		x = x*x % MOD;
	}
	return result;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		tot = 0;
		memset(dp, 0, sizeof(dp));
		h[0] = 0;
		dp[0][0] = 1;

		for(int i = 1; i <= n; ++i) {
			scanf("%d", &h[i]);
			Has[++tot] = h[i];
		}
		sort(Has + 1, Has + tot + 1);
		tot = unique(Has+1, Has + tot + 1) - Has - 1;
		
		for(int i = 1; i <= n; ++i) {
			h[i] = lower_bound(Has + 1, Has + tot + 1, h[i]) - Has;
		}
		
		
		for(int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i-1][0] * 2 % MOD;
			for(int j = h[i] + 1; j <= h[i-1]; ++j) dp[i][0] = (dp[i][0] + dp[i-1][j] * 2 % MOD) % MOD;

			ll tmpPow = Pow(2, Has[h[i]] - Has[h[i-1]]);
			for(int j = 1; j <= min(h[i-1], h[i]) ; ++j) {
				dp[i][j] = dp[i-1][j] * tmpPow % MOD;
			}

			for(int j = h[i-1] + 1; j <= h[i]; ++j) {
				dp[i][j] = (dp[i][j] + j==1? ( dp[i-1][0] * ( Pow(2, Has[j]) - 2) % MOD * Pow(2, Has[h[i]] - Has[j]) % MOD ) :
											 ( dp[i-1][0] * 2 * (Pow(2, Has[j]-Has[j-1]) - 1) % MOD * Pow(2, Has[h[i]]-Has[j]) % MOD ) 
											 ) %MOD;
			}
		}


		ll result = 0;
		for(int i = 0; i <= tot; ++i) {
			result = (result + dp[n][i]) % MOD;
		}
		printf("%lld\n", result);
	}
	return 0;
}