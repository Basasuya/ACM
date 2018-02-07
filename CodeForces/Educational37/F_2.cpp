#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 6e5+5;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int n, m;
int a[N];
ll sum[N << 2];
int maxx[N << 2];
inline int D(int x) {
	int ans = 0;
	int sqx = (int)sqrt(x);
	for(int i = 1; i <= sqx; ++i) {
		if(x % i == 0)
			ans += 2;
	}
	if(sqx * sqx == x)
	   ans --;
	return ans;	
}
inline void Up(int rt) {
	maxx[rt] = max(maxx[rt << 1],  maxx[rt << 1 | 1]);
	sum[rt] = sum[rt << 1] + sum[rt << 1|1];
}
void Build(int l, int r, int rt) {
	if(l == r) {
		maxx[rt] = a[l];
		sum[rt] = a[l];
		return ;
	}
	int m = (l + r) >> 1;
	Build(lson); Build(rson);
	Up(rt);
}
void Update(int L, int R, int l, int r, int rt) {
	if(maxx[rt] <= 2) return;
	if(l == r) {
		sum[rt] = maxx[rt] = D(sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	if(L <= m) Update(L, R, lson);
	if(R > m) Update(L, R, rson);
	Up(rt);
}
void Debug(int l, int r, int rt) {
	printf("%d %d:%d %lld\n", l, r, maxx[rt], sum[rt]);
	if(l == r) {
		return;
	}
	int m = (l + r) >> 1;
	Debug(lson); Debug(rson);
}
ll Sum(int R, int l, int r, int rt) {
	if(R == 0) return 0;
	if(r <= R) return sum[rt];
	int m = (l + r) >> 1;
	ll ans = Sum(R, lson);
	if(R > m) ans += Sum(R, rson);
	return ans;
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		Build(1, n, 1);
		for(int i = 0; i < m; ++i) {
			int t, l, r; 
			scanf("%d %d %d", &t, &l, &r);
			if(t == 1)
				Update(l, r, 1, n, 1);
			else printf("%lld\n", Sum(r, 1, n, 1) - Sum(l-1, 1, n, 1));
		//	printf("Debug:\n"); Debug(1, n, 1); printf("\n");
		}
	}
	return 0;
}
