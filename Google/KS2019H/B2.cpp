#include <bits/stdc++.h>
using namespace std;
 
const int N = 405;
 
struct edge {
    int to, c;
};
 
int n;
string str[N];
vector<edge> G[N];
int vis[N];
int cnt[2];
 
void dfs(int v, int c) {
    vis[v] = c;
    cnt[c]++;
    for(auto e : G[v]) {
        if(vis[e.to] == -1) dfs(e.to, e.c ^ c);
        if(vis[e.to] != -1) assert(vis[e.to] == (e.c ^ c));
    }
}
 
void solve(int t) {
    cin >> n;

    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < 4 * n - 2; i++) G[i].clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int u = i + j, v = 2 * n - 1 + (i + (n - 1) - j);
            G[u].push_back({v, str[i][j] == '.'});
            G[v].push_back({u, str[i][j] == '.'});
        }
    }
    fill(vis, vis + 4 * n - 2, -1);
    int res = 0;

    int ccnt = 0;
    for(int i = 0; i < 4 * n - 2; i++) {
        if(vis[i] == -1) {
            ccnt ++;
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
            res += min(cnt[0], cnt[1]);
        }
    }
    assert(n == 1 || ccnt == 2);
    // printf("%d\n", ccnt);

    cout << "Case #" << t << ": " << res << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        solve(t);
    }
 
}