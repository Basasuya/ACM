#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int INF = 0x3f3f3f3f;
int A[MAXN];
int B[MAXN]; int cnt = 0;
int ans;
int N, K, Q;


void solve(int x) {
	vector<int> tmp, all;
	for(int i = 1; i <= N; ++i) {
		if(A[i] >= x) tmp.push_back(A[i]);
		else if((int)tmp.size() >= K){
			sort(tmp.begin(), tmp.end());
			for(int j = 0; j < (int)tmp.size() - K + 1; ++j) 
				all.push_back(tmp[j]);
			tmp.clear();
		} else tmp.clear();
	}
	if((int)tmp.size() >= K){
		sort(tmp.begin(), tmp.end());
		for(int j = 0; j < (int)tmp.size() - K + 1; ++j) 
			all.push_back(tmp[j]);
		tmp.clear();
	}
//	printf("%d\n", (int)all.size());
	
	if((int)all.size() < Q) return;

	sort(all.begin(), all.end());
//	printf("%d\n", all[0]);
	ans = min(ans, all[Q - 1] - all[0]);
}
int main() {
//	freopen("in.txt", "r", stdin);
	while(~scanf("%d %d %d", &N, &K, &Q)) {
		cnt = 0;
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
			B[cnt ++] = A[i];
		}
		sort(B,B + cnt);
		cnt = unique(B, B+cnt) - B;
		
		ans = INF;
		for(int i = 0; i < cnt; ++i) {
			solve(B[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
