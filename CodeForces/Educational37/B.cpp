#include<iostream>
#include<map>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
const int MOD = 1e9+7;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)
const int INF = 0x3f3f3f3f;

int ans[N];

int main() {
	int t; scanf("%d", &t);
	int n;
	while(t --) {
		scanf("%d", &n);
		int nowTime = 1;
		for(int i = 0; i < n; ++i) {
			int l, r; scanf("%d %d", &l, &r);
			if(r >= nowTime) {
				ans[i] = max(nowTime, l);
				nowTime = ans[i] + 1;
			}
			else {
				ans[i] = 0;
			}
		}
		for(int i = 0; i < n; ++i) printf("%d ", ans[i]); printf("\n");
	}
	return 0;
}
