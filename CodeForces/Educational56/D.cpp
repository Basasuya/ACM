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
const int N = 3e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int n, m;
struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int vis[N];
ll two[N];
int all;
int odd;
bool suc;
void dfs(int x, int pre) {
    if(suc == false) return;
    all ++;
    if(vis[x] == 1) odd ++;
    for(int i = head[x]; ~i && suc; i = E[i].nx) {
        int to = E[i].to; 
        if(to == pre) continue;
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to, x);
        }else if (vis[to] != (vis[x] ^ 1) ) {
            suc = false;
        }
    }
}
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    two[0] = 1; 
    for(int i = 1; i < N; ++i) two[i] = two[i-1] * 2 % MOD;
    // printf("%d\n", two[1]);
    while(t --) {
        memset(head, -1, sizeof(head));
        memset(vis, -1, sizeof(vis));
        tot = 0;

        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }
        suc = true;
        ll ans = 1;
        for(int i = 1; i <= n && suc; ++i) {
            if(vis[i] == -1) {
                vis[i] = 0; all = 0; odd = 0; 
                dfs(i, i);
                // ll tmp = (Pow(2, odd) + Pow(2, all - odd)) % MOD;
                ll tmp = (two[odd] + two[all - odd]) % MOD;
                ans = ans * tmp % MOD;
            }
        }

        if(suc == false) printf("0\n");
        else printf("%lld\n", ans);
    }
    return 0;
}