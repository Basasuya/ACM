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
const int MOD = 1000000007;
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
bool tag;
void dfs(int x, int pre) {
    // printf("%d %d\n", x, pre);
    if(tag) return;
    for(int i = head[x]; ~i && !tag; i = E[i].nx) {
        int to = E[i].to; if(to == pre) continue;
        if(vis[to]) {
            int tt = vis[x] - vis[to];
            if(tt % 2 == 0) tag = true;
            continue;
        }   
        vis[to] = vis[x] + 1;
        dfs(to, x);
    }
}
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        tag = false;
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < m; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }

        if(n == 1) {
            printf("1\n");
            continue;
        }
        vis[1] = 1;
        dfs(1, 1);

        printf("%d\n", tag ? 3 : 2);    
    }
    return 0;
}