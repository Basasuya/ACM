#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	for (int rep = 1; rep <= Q; ++rep) {
		int N, K;
		cin >> N >> K;
		vector<int> P(N), A(N);
		for (int i = 0; i < N; ++i) cin >> P[i];
		for (int i = 0; i < N; ++i) cin >> A[i];
		vector<int> comp = A;
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for (int i = 0; i < N; ++i) {
			A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
		}
		int M = comp.size();
		vector<vector<int> > G(M);
		for (int i = 0; i < N; ++i) {
			G[A[i]].push_back(P[i]);
		}
		for (int i = 0; i < M; ++i) {
			sort(G[i].begin(), G[i].end());
		}
		vector<vector<int> > ldp(M + 1, vector<int>(K + 1, inf)), rdp(M + 1, vector<int>(K + 1, inf));
		ldp[0][0] = 0; rdp[M][0] = 0;
		for (int i = 0; i < M; ++i) {
			ldp[i + 1] = ldp[i];
			for (int j = 1; j <= G[i].size(); ++j) {
				for (int k = j; k <= K; ++k) {
					ldp[i + 1][k] = min(ldp[i + 1][k], ldp[i][k - j] + G[i][j - 1] * 2);
				}
			}
			for (int j = K - 1; j >= 0; --j) {
				ldp[i + 1][j] = min(ldp[i + 1][j], ldp[i + 1][j + 1]);
			}
		}
		for (int i = M - 1; i >= 0; --i) {
			rdp[i] = rdp[i + 1];
			for (int j = 1; j <= G[i].size(); ++j) {
				for (int k = j; k <= K; ++k) {
					rdp[i][k] = min(rdp[i][k], rdp[i + 1][k - j] + G[i][j - 1] * 2);
				}
			}
			for (int j = K - 1; j >= 0; --j) {
				rdp[i][j] = min(rdp[i][j], rdp[i][j + 1]);
			}
		}
		int ans = inf;
		for (int i = 0; i < M; ++i) {
			for (int j = 1; j <= G[i].size() && j <= K; ++j) {
				for (int k = 0; k <= K - j; ++k) {
					ans = min(ans, ldp[i][k] + rdp[i + 1][K - j - k] + G[i][j - 1]);
				}
			}
		}
		cout << "Case #" << rep << ": " << ans << endl;
	}
	return 0;
}