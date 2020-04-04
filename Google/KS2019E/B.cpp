#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n, m;
PII a[N];
int s[N];
int t[N];

bool cmp(PII x, PII y) {
	return (ll)x.fi*y.se > (ll)y.fi*x.se;
}

ll crs(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

bool ff(int x, int y) {
	if (x > s[n]) return false;
	int c = lower_bound(s, s+n+1, x)-s;
	if (c) c--;
	return crs(x-s[c], y-(t[n]-t[c+1]), a[c].fi, 0, 0, a[c].se) >= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> m >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i].fi >> a[i].se;
		}
		sort(a, a+n, cmp);
		s[0] = t[0] = 0;
		for (int i = 0; i < n; i ++) {
			s[i+1] = s[i] + a[i].fi;
			t[i+1] = t[i] + a[i].se;
		}
		printf("Case #%d: ", __);
		while (m--) {
			int x, y;
			cin >> x >> y;
			putchar(ff(x, y) ? 'Y': 'N');
		}
		puts("");
	}
	return 0;
}
