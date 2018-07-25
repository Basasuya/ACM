#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
const int N = 262200;
const ll INF = 1e18;

int A[N];
pair<int, int> dp[N];

void update(pair<int,int> &A, int x) {
	if(x > A.second) {
		A.second = x;
		if(A.second > A.first) {
			swap(A.second, A.first);
		}
	}
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int nLen = (1<<n) - 1;
	
		for(int i = 0; i <= nLen; ++i) {
			scanf("%d", &A[i]);
			dp[i] = make_pair(A[i], -1);
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j <= nLen; ++j) {
				if( ((j >> i) & 1) == 0 ) {
					int newI = j | (1 << i);
					int t1 = dp[j].first;
					int t2 = dp[j].second;
					update(dp[newI], t1);
					update(dp[newI], t2);
				}
			}
		}

	//	for(int i = 0; i <= nLen; ++i) printf("%d %d\n", dp[i].first, dp[i].second);
		int ans = -1;
		for(int i = 1; i <= nLen; ++i) {
			ans = max(ans, dp[i].first + dp[i].second);
			printf("%d\n", ans);
		} 
	}
	return 0;
}