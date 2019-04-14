#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <time.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

ll a[10];
ll dp[10][8400];

int main() {
    ll w;
    while(~scanf("%lld", &w)) {
        for(int i = 0; i < 8; ++i) {
            scanf("%lld", &a[i]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8400; ++j) {
                if(dp[i][j] == -1) continue;
                int edge = min(1ll * 840 / (i + 1), a[i]); 
                for(int k = 0; k <= edge; ++k) {
                    dp[i + 1][j + k * (i + 1)] = max( dp[i + 1][j + k * (i + 1)], dp[i][j] + (a[i] - k) / (840 / (i + 1)));
                }
            }
        }

        ll ans = -1;
        for(int i = 0; i < 8400; ++i) {
            if(dp[8][i] == -1 || i > w) continue;
            ans = max(ans, i + min( (w - i) / 840, dp[8][i]) * 840);
        }
        printf("%lld\n", ans);
    }
    return 0;
}