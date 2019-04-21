#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pli pair<ll, int>
#define pil pair<int, ll>
#define clr(a, x) memset(a, x, sizeof(a))

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define TREE tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update>
TREE T;
*/

int T, n, s, a[100015], b[100015], rec[100015], ma[400015], lazy[400015];
vector<int> p[100015];
void pushdown(int i) {
	if (lazy[i]) {
		ma[i << 1] += lazy[i];
		ma[i << 1 | 1] += lazy[i];
		lazy[i << 1] += lazy[i];
		lazy[i << 1 | 1] += lazy[i];
		lazy[i] = 0;
	}
}
void pushup(int i) {
	ma[i] = max(ma[i << 1], ma[i << 1 | 1]);
}
void build(int i, int l, int r) {
    lazy[i] = 0;
	if (l == r) {
		ma[i] = b[l];
		return;
	}
	int mi = l + r >> 1;
	build(i << 1, l, mi);
	build(i << 1 | 1, mi + 1, r);
	pushup(i);
}

void update(int i, int l, int r, int x, int y, int z) {
	if (x <= l && r <= y) {
		ma[i] += z;
		lazy[i] += z;
		return;
	}
	pushdown(i);
	int mi = l + r >> 1;
	if (x <= mi) update(i << 1, l, mi, x, y, z);
	if (mi < y) update(i << 1 | 1, mi + 1, r, x, y, z);
	pushup(i);
}
int query(int i, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return ma[i];
	}
	pushdown(i);
	int mi = l + r >> 1;
	int res1 = 0, res2 = 0;
	if (x <= mi) res1 = query(i << 1, l, mi, x, y);
	if (mi < y) res2 = query(i << 1 | 1, mi + 1, r, x, y);
	return max(res1, res2);
}
int main() {
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		scanf("%d%d", &n, &s);
		clr(b, 0); for (int i = 1; i <= 100000; ++i) p[i].clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			p[a[i]].pb(i);
			rec[i] = p[a[i]].size();
		}
		for (int i = 1; i <= 100000; ++i) p[i].pb(n + 1);
		for (int i = 1; i <= n; ++i) {
			b[i] += b[i - 1] + 1;
			if (rec[i] == s + 1) b[i] -= s + 1;
			else if (rec[i] > s + 1) --b[i];
		}
		build(1, 1, n); int ans = 0;
		for (int l = 1; l <= n; ++l) {
			int q = query(1, 1, n, l, n);
			ans = max(ans, q); int pp = a[l];
			if (rec[l] + s < (int)p[pp].size()) {
				int x = rec[l] + s - 1;
				update(1, 1, n, l, p[pp][x] - 1, -1);
				update(1, 1, n, p[pp][x], p[pp][x + 1] - 1, s);
			} else {
				update(1, 1, n, l, n, -1);
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}

