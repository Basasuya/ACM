#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> G[N];
int a[N], n;

typedef long long ll;
const ll INF = 1e18;
ll dp[N][2][2];
void Maxi(ll &a, ll b) {
    if (b > a) a = b;
}
void dfs(int v, int p) {
    for (auto u: G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }

    // 0 0
    ll s0=0, smax=0, dmax=-INF;
    for (auto u: G[v]) {
        if (u == p) continue;
        s0 += dp[u][0][0];
        smax += max(dp[u][0][0], dp[u][0][1]);
        Maxi(dmax, dp[u][0][1]-dp[u][0][0]);
    }
    dp[v][0][0] = s0;
    if (dmax >= 0) Maxi(dp[v][0][0], smax+a[v]);
    else if (dmax > -INF) {
        Maxi(dp[v][0][0], smax+dmax+a[v]);
    }

    // 0 1

    dp[v][0][1] = a[v];

    for (auto u: G[v]) {
        if (u == p) continue;
        dp[v][0][1] += max(dp[u][1][0], dp[u][1][1]);
    }

    // 1 0

    dp[v][1][0] = a[v] + smax;

    
    dp[v][1][1] = dp[v][0][1];
    
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    for (int i = 0; i < n-1; i++) {
        int u,v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    printf("%lld\n", max(dp[1][0][0], dp[1][0][1]));

    for (int i = 1; i <= n; i++) G[i].clear();
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}