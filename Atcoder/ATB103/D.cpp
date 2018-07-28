#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll INF = 1e18;
 
int dp[N];
int has[N];
vector<int> tmp;
vector<int> tar[N];
 
 
int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
 
		dp[0] = 0;
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			tar[a].push_back(b);
			dp[2*a] ++;
			dp[2*b - 1] --;
		}
	//	for(int i = 1; i <= 2*n; ++i) printf("%d ", dp[i]); printf("\n");
		int ans = 0;
		int flag = 0;
		for(int i = 1; i <= 2*n; ++i) {
			if(dp[i] > 0) {
				for(int j = 0; j < tar[(i+1)/2].size(); ++j) 
					tmp.push_back(tar[(i+1)/2][j]);
				flag = 1;
			} else if(dp[i] < 0 && flag) {
				flag = 0;
				ans ++;
				for(int j = 0; j < tmp.size(); ++j) {
					dp[2*tmp[j] - 1] ++;
				}
				tmp.clear();
			}
		}
 
		printf("%d\n", ans);
		
	}
	return 0;
}