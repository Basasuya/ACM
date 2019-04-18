#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int N = 1e5 + 5;
struct Node{
    int fr, to, nx, dis;
}E[N << 2], F[N << 2];
int head[N]; int tot = 0; 
int headF[N]; int totF = 0;
int n, m, q;
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
void addF(int fr, int to) {
    F[totF].to = to; F[totF].nx = headF[fr]; headF[fr] = totF ++;
}

int dfn[N], low[N], belong[N], isbridge[N << 2];
int bcc_cnt, dfn_tim;
int Father[N];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dfn_tim;
    // cout << u <<" "<< dfn[u] << endl;
    for(int i = head[u]; ~i; i = E[i].nx) {
        int v = E[i].to;
        if(!dfn[v]) {
            tarjan(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                isbridge[i] = isbridge[i ^ 1] = 1;
            }
        } else if(dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void dfs(int u) {
    dfn[u] = 1;
    belong[u] = bcc_cnt;
    for(int i = head[u]; ~i; i = E[i].nx) {
        int v = E[i].to;
        if(!isbridge[i] && !dfn[v]) {
            dfs(v);
        }
    }
}


void find_ebcc() {
    dfn_tim = bcc_cnt = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(isbridge,0,sizeof isbridge);
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i])
            tarjan(i,-1);
    }
    memset(dfn, 0, sizeof dfn);
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            bcc_cnt++;
            dfs(i);
        }
    }
}

int Find(int x) { if(Father[x] == x) return  x; else return Father[x] = Find(Father[x]); }

const int DEG = 20;
int fa[N][DEG];
int deg[N];

void bfs(int root) {  
	queue<int>que;
	deg[root] = 0;
	fa[root][0] = root;
	que.push(root);
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
        // printf("%d\n", tmp);
		for (int i = 1; i < DEG; i++){  
			fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
		}
		for (int i = headF[tmp]; ~i; i = F[i].nx) {
			int v = F[i].to;
			if (v == fa[tmp][0]) continue;
			deg[v] = deg[tmp] + 1;
			fa[v][0] = tmp;
			que.push(v);
		}
	}
}
int lca(int u, int v) {
	if (deg[u] > deg[v]) swap(u, v);   
	int hu = deg[u], hv = deg[v];
	int tu = u, tv = v;
	for (int det = hv - hu, i = 0; det; det >>= 1, i++)   
	if (det & 1){
		tv = fa[tv][i];
	}
	if (tu == tv)return tu;  
	for (int i = DEG - 1; i >= 0; i--) {
		if (fa[tu][i] == fa[tv][i])
			continue;
		tu = fa[tu][i];
		tv = fa[tv][i];
	}
	if (fa[tu][0] == fa[tv][0]){    
		return fa[tu][0];
	}
	else
		return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        memset(headF, -1, sizeof(headF));
        memset(head, -1, sizeof(head));
        tot = 0;
        totF = 0;

        
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 0; i <= n; ++i) Father[i] = i;
        for(int i = 0; i < m; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            add(l, r);
            add(r, l);
        }

        find_ebcc();
        map<pair<int, int>, int> hashGraph;
        for(int i = 1; i <= n; ++i) {
            for(int j = head[i]; ~j; j = E[j].nx) {
                int to = belong[E[j].to];
                int fr = belong[i];
                if(fr > to) swap(fr, to);
                if(hashGraph.find(make_pair(fr, to)) == hashGraph.end() && fr != to) {
                    addF(fr, to);
                    addF(to, fr);
                    hashGraph[make_pair(fr, to)] = 1;

                    int father1 = Find(fr); int father2 = Find(to);
                    if(father1 != father2) 
                        Father[father1] = father2;
                }
            }
        }

        for(int i = 1; i <= bcc_cnt; ++i) {
            if(Father[i] == i) {
                bfs(i);
            }
        }
        while(q --) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            int U = belong[u];
            int V = belong[v];
            int W = belong[w];
            int faU = Find(U);
            int faV = Find(V);
            int faW = Find(W);
            if(faU != faV || faV != faW) printf("No\n");
            else {
                int uv = lca(U, V);
                int vw = lca(V, W);
                int uw = lca(U, W);
                int uvw = lca(U, vw);
                if(V == W) {
                    if(U == W) printf("Yes\n");
                    else printf("No\n");
                } else {
                    if(uvw == vw && (U == uv || U == uw)) printf("Yes\n");
                    else printf("No\n");
                }
            }
        }
        
    }
    return 0;
}

/*
100
5 5 1
1 2
1 3
2 4
3 4
4 5
2 4 5

6 7 4
1 2
2 3
3 1
4 5
5 6
6 4
1 4
4 1 3
1 4 2
1 2 3
1 3 3
2 1 2
1 2
1 1 1
2 1 2

*/