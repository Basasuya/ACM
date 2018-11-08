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
const int N = 2005;
const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

struct Node{
  int fr, to, nx, di;
}E[N*2];
int head[N], tot;
void add(int fr, int to) {
  E[tot].to = to;  E[tot].nx = head[fr];
  head[fr] = tot ++;
}

int Size[N], dp[N][N], h[N];
int n, T;

void dfs(int x, int pre) {
    // printf("%d %d\n", x , pre);
    Size[x] = 1;
    dp[x][1] = 1;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        dfs(to, x);
        
        for(int j = 0; j <= min(T, Size[x] + Size[to]); ++j) h[j] = 0;
        for(int j = 1; j <= min(Size[x], T); ++j) {
            for(int k = 0; k <= min(Size[to], T); ++k) {
                h[j + k] = (h[j + k] + 1ll * dp[x][j] * dp[to][k]) % MOD;
            }
        }
        Size[x] += Size[to];
        for(int j = 0; j <= min(T, Size[x]); ++j) dp[x][j] = h[j];
    }
    for(int i = 1; i <= min(T, Size[x]); ++i) dp[x][0] = (1ll * dp[x][0] + dp[x][i]) % MOD;
}
int main() {
    while(~scanf("%d %d", &n, &T)) {
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }
        dfs(1, 1);
        printf("%d\n", dp[1][0]);
    }
    return 0;
}