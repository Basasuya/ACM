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
int L, R;
int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> L >> R;
		memset(a, 0, sizeof a);
		for (int i = 1; i*i <= R; i ++) {
			int le = L/i*i;
			if (le < L) le += i;
			for (int j = le; j <= R; j += i) {
				int k = j/i;
				if (i <= k) {
					if (i&1) a[j-L]++; else a[j-L]--;
				}
				if (i < k) {
					if (k&1) a[j-L]++; else a[j-L]--;
				}
			}
		}
		int S = 0;
		for (int i = 0; i <= R-L; i ++)
			if (abs(a[i]) <= 2) S++;
		printf("Case #%d: %d\n", __, S);
	}
	return 0;
}
