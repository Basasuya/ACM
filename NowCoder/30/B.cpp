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
const int N = 1e4+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

struct Node{
  int fr, to, nx, di, ti;
}E[N*2];
int head[N], tot;
int dp[N][2];
void add(int fr, int to, int di) {
  E[tot].to = to; E[tot].di = di; E[tot].nx = head[fr];
  head[fr] = tot ++;
}
ll ans = 0;
void dfs(int x, int pre) {
    dp[x][0] = 1; dp[x][1] = 0;
    int cnt = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        dfs(to, x);
        cnt ++; 
        if(E[i].di) {
            ans += 1ll * dp[x][0] * dp[to][1] * (dp[to][1] - 1) * 3;
            ans += 1ll * dp[x][0] * dp[to][1] * (dp[x][0] - 1) * 3;
            ans += 1ll * dp[x][1] * dp[to][0] * (dp[to][0] - 1) * 3;
            ans += 1ll * dp[x][1] * dp[to][0] * (dp[x][1] - 1) * 3;
            ans += 1ll * dp[x][0] * dp[to][1] * 6;
            ans += 1ll * dp[x][1] * dp[to][0] * 6;
            dp[x][0] += dp[to][1];
            dp[x][1] += dp[to][0];
        } else {
            ans += 1ll * dp[x][0] * dp[to][0] * (dp[to][0] - 1) * 3;
            ans += 1ll * dp[x][0] * dp[to][0] * (dp[x][0] - 1) * 3;
            ans += 1ll * dp[x][1] * dp[to][1] * (dp[to][1] - 1) * 3;
            ans += 1ll * dp[x][1] * dp[to][1] * (dp[x][1] - 1) * 3;
            ans += 1ll * dp[x][0] * dp[to][0] * 6;
            ans += 1ll * dp[x][1] * dp[to][1] * 6;
            dp[x][0] += dp[to][0];
            dp[x][1] += dp[to][1];
        }
    }
    // printf("%d: %d %d\n", x, dp[x][0], dp[x][1]); 
    // ans += 1ll * (dp[x][0] - 1) * (dp[x][0] - 2) / 2 * 6 + 1; 
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        ans = 0;
        memset(head, -1, sizeof(head));
        tot = 0;

        for(int i = 1; i < n; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            c %= 2;
            add(a, b, c); add(b, a, c);
        }

        dfs(1, 1);
        printf("%lld\n", ans + n);
    }
    return 0;
}

/*

7
1 2 3
1 3 4
2 4 5
2 5 8
3 6 10
3 7 11
*/