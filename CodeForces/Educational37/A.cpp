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
const int N = 1e5 + 5;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)
const int INF = 0x3f3f3f3f;

int has[N];
int main() {
	int t; 
	int n, k;
	scanf("%d", &t);
	while(t --) {
		scanf("%d %d", &n, &k);
		memset(has, INF, sizeof(has));
		for(int i = 0; i < k; ++i) {
			int a; scanf("%d", &a);
			int l = a, r = a;
			int cnt = 0;
			while(l >= 1 || r <= n) {
				cnt ++;
				if(l >= 1) has[l] = min(has[l], cnt);
				if(r <= n) has[r] = min(has[r], cnt);
				l --; r ++;
			}
		}
		int ans = -1;
		for(int i = 1; i <= n; ++i) {
			ans = max(ans, has[i]);
		}
		printf("%d\n", ans);
	}
}
