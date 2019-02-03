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

int s[N], t[N], d[N], w[N];
ll dp[N][205];
vector<int> ed[N];
vector<int> st[N];
pair<int, int> choose[N];
int main() {
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        // memset(choose, -1, sizeof(choose));
        // memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n + 1; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i][j] = 1e18;
            }
        }
        for(int i = 0; i < k; ++i) {   
            scanf("%d %d %d %d", &s[i], &t[i], &d[i], &w[i]);
            st[s[i]].push_back(i);
            ed[t[i] + 1].push_back(i);
        }
        multiset<pair<int, int> > best;
        for(int i = 1; i <= n; ++i) {
            choose[i] = make_pair(-1, -1);
            for(int j = 0; j < st[i].size(); ++j) {
                best.insert(make_pair(w[st[i][j]], d[st[i][j]]));
            }
            for(int j = 0; j < ed[i].size(); ++j) {
                best.erase(best.find(make_pair(w[ed[i][j]], d[ed[i][j]])));
            }
            if(!best.empty()) {
                choose[i] = (*(--best.end()));
            }
            // printf("%d %d\n", choose[i].first, choose[i].second);
        }
        // printf("hhh\n");

        dp[1][m] = 0;
        for(int i = 1; i <= n; ++i) {
            if(choose[i].first == -1) {
                for(int j = 0; j <= m; ++j) {
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                }
            } else {
                for(int j = 1; j <= m; ++j) {
                    dp[i + 1][j - 1] = min(dp[i][j], dp[i + 1][j - 1]);
                }
                // printf("%d %d: ", choose[i].first, choose[i].second); for(int z = 1; z <= n; ++z) for(int j = 0; j <= m; ++j) printf("%lld ", dp[z][j]); printf("\n");
                for(int j = 0; j <= m; ++j) {
                    dp[choose[i].second + 1][j] = min(dp[choose[i].second + 1][j], dp[i][j] + choose[i].first);
                }
            }
            // printf("%d %d: ", choose[i].first, choose[i].second); for(int z = 1; z <= n + 1; ++z) for(int j = 0; j <= m; ++j) printf("%lld ", dp[z][j]); printf("\n");
        }

        ll ans = 1e18;
        for(int i = 0; i <= m; ++i) {
            ans = min(ans, dp[n + 1][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}