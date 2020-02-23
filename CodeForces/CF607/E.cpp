#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll mx, mi;
int t, head[N], len, k, vis[N];
struct edge {
	int v, w, next;
} e[N * 2];
void add(int u, int v, int w) {
	e[len].v = v;
	e[len].w = w;
	e[len].next = head[u];
	head[u] = len++;
}
void dfs(int u, int fa) {
	vis[u] = 1;
	for (int j = head[u]; j; j = e[j].next) {
		int v = e[j].v;
		int w = e[j].w;
		if (v == fa) continue;
		dfs(v, u);
		if (vis[v] & 1) {
			mi += w;
		}
		//防止越界 
		mx += (ll)min(k - vis[v], vis[v]) * w;
		vis[u] += vis[v];
	} 
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		int u, v, w;
		k <<= 1;
		len = 1;
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < k; i++) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		mi = 0, mx = 0;
		dfs(1, 0);
		printf("%lld %lld\n", mi, mx);
	}
	return 0;
}