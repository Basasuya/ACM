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

const int DEG = 20;
int fa[N][DEG];
int deg[N];

struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

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