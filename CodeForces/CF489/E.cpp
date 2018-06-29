#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int n, q;
int A[N];
int maxx[N << 2];
ll sum[N << 2];
void Build(int l, int r, int rt) {
	if(l == r) {
		sum[rt] = A[l];
		maxx[rt] = A[l];
		return;
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	sum[rt] = sum[rt << 1] + sum[rt << 1|1];
	maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
}
void Update(int pos, int num, int l, int r, int rt) {
	if(l == r) {
		sum[rt] = num;
		maxx[rt] = num;
		return;
	}
	int m = (l + r) >> 1;
	if(pos <= m) Update(pos, num, lson);
	else Update(pos, num, rson);
	sum[rt] = sum[rt << 1] + sum[rt << 1|1];
	maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
}
ll Sum(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	ll ret = 0;
	if(L <= m) ret += Sum(L, R, lson);
	if(R > m) ret += Sum(L, R, rson);
	return ret;
}

pair<ll, int> Ans;
void Find(int L, int R, ll num, int l, int r, int rt) {
	if(l == r) {
		Ans = make_pair(maxx[rt], l);
		return;
	} 
	int m = (l + r) >> 1;
	if(maxx[rt << 1] >= num && L <= m) Find(L, R, num, lson);
	if(maxx[rt<<1|1] >= num && R > m && Ans.first == -1) Find(L, R, num, rson);
}
int main() {
	while(~scanf("%d %d", &n, &q)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		Build(1 , n, 1);
	//	printf("%lld\n", Sum(1, 2, 1, n, 1));
		for(int i = 0; i < q; ++i) {
			int a, b; scanf("%d %d", &a, &b);
			Update(a, b, 1, n, 1);
			A[a] = b;
			if(A[1] == 0) printf("1\n");
			else if(A[1] == A[2]) printf("2\n");
			else {
				int pre = 2;
				while(1) {
					ll tmpTarget = Sum(1, pre, 1, n, 1);
					if(tmpTarget > maxx[1]) {
						printf("-1\n");
						break;
					}
					Ans = make_pair(-1, -1);
					Find(pre+1, n, tmpTarget, 1, n, 1);
					if(Ans.first == -1) {
						printf("-1\n");
						break;
					}
					ll nowTarget = Sum(1, Ans.second-1, 1, n, 1);
					if(Ans.first == nowTarget) {
						printf("%d\n", Ans.second);
						break;
					} else {
						pre = Ans.second;
					}
						
				}
			}
		}
	}
	return 0;
}


/*
3 3
1 0 0
1 2
1 2
1 2





*/
