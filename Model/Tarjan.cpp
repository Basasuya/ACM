#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int Maxn = 1e6;

int N, M;
vector<int> G[Maxn + 5];

int dfn[Maxn + 5], low[Maxn + 5], dcnt;
int col[Maxn + 5], ccnt;
bool vis[Maxn + 5];
int stk[Maxn + 5], tp;

void Tarjan_scc(int u) {
	dfn[u] = ++dcnt, low[u] = dcnt, vis[u] = true;
	stk[++tp] = u;
	for(int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		if(!dfn[v]) {
			Tarjan_scc(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) low[u] = min(low[u], low[v]);
	}
	if(dfn[u] == low[u]) {
		++ccnt;
		while(true) {
			col[stk[tp]] = ccnt;
			vis[stk[tp]] = false;
			if(stk[tp--] == u)
				break;
		}
	}
}

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);
		ccnt = 0;
		for(int i = 1; i <= N; i++)
			dfn[i] = 0, G[i].clear();
		for(int i = 1; i <= M; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if(u == v) continue;
			G[u].push_back(v);
		}
		for(int i = 1; i <= N; i++)
			if(!dfn[i]) Tarjan_scc(i);
		if(ccnt == 1) puts("No");
		else {
			puts("Yes");
			int cnt_j = 0, cnt_p = 0;
			for(int i = 1; i <= N; i++)
				if(col[i] == 1) cnt_j++;
				else cnt_p++;
			printf("%d %d\n", cnt_j, cnt_p);
			for(int i = 1; i <= N; i++)
				if(col[i] == ccnt) printf("%d ", i);
			puts("");
			for(int i = 1; i <= N; i++)
				if(col[i] != ccnt) printf("%d ", i);
			puts("");
		}
	}
	return 0;
}
