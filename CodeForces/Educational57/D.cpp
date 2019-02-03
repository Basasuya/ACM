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
const int MOD = 998244353;
typedef long long ll;

int a[N];
char seq[N];
char tmp[] = "*hard";
ll dp[N][5];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, INF, sizeof(dp));

        scanf("%s", seq + 1);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);

        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            int tag = 0;
            for(int j = 1; j <= 4; ++j) {
                if(tmp[j] == seq[i]) {
                    tag = j; break;
                }
            }
            if(tag) {
                dp[i][tag - 1] = min(dp[i][tag - 1], dp[i - 1][tag - 1] + a[i]);
                dp[i][tag] = min(dp[i][tag], dp[i - 1][tag - 1]);
            }
            // printf("%d\n", tag);
            for(int j = 0; j <= 4; ++j) {
                if(j != tag - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            // for(int j = 0; j <= 4; ++j) printf("%d ", dp[i][j]); printf("\n");
        }

        ll ans = 1e18;
        for(int i = 0; i < 4; ++i) ans = min(ans, dp[n][i]);
        printf("%lld\n", ans);


    }
    return 0;
}