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
const int N = 100005;
const int M = 200005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

struct Node{
  int fr, to, nx, di;
}E[M*2];
int head[N], tot;
void add(int fr, int to) {
  E[tot].to = to;  E[tot].nx = head[fr];
  head[fr] = tot ++;
}
int vis[N];
ll dp[2][N][N];
ll flag[N];
int n, T;

void dfs(int x, int pre) {
    int tmp[N];
    flag[x] = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        dfs(to, x);
        for(int j = 1; j <= T; ++j) {
            for(int k = 0; k <= j; ++k) {
                dp[flag[x]][x][j+1] = (dp[flag[x]][x][j] + dp[flag[x] ^ 1][x][j - k] * dp[flag[to]][to][k]) % MOD;
            }
        }

    }
}
int main() {
    while(~scanf("%d %d", &n, &T)) {
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }

        dfs(1, 1);

    }
    return 0;
}