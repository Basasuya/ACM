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
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;

struct Node{
    int to, nx, di;
}E[N * 2];
int head[N]; int tot;
void add(int fr, int to, int di) {
    E[tot].to = to; E[tot].nx = head[fr]; E[tot].di = di; head[fr] = tot ++;
}

ll sum[N];
ll dp[N];
int cnt[N];
void dfs(int x, int pre) {
    sum[x] = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        dfs(to, x);
        sum[x] += E[i].di + sum[to];
    }
}

void dfs2(int x, int pre) {
    dp[x] = 2e18;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        dfs2(to, x);
        dp[x] = min(dp[x], 2*(sum[x] - sum[to]) - E[i].di + dp[to]);
    }
    if(dp[x] == 2e18) dp[x] = 0;
 //   printf("%d %lld\n", x, dp[x]);
}

int main() {
    int n, st;
    while(~scanf("%d %d", &n, &st)) {
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        memset(head, -1, sizeof(head));
        tot = 0;
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
            cnt[v] ++; cnt[u] ++;
        }

        dfs(st, st);
    //    for(int i = 1; i <= n; ++i) printf("%lld ", sum[i]); printf("\n");
        dfs2(st, st);

        printf("%lld\n", dp[st]);
    }
    return 0;
}