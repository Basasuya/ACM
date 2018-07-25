#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
 
int A[N];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}
		int ans = 0;
		int cnt = 1;
		for(int i = 1; i < n; ++i) {
			if(A[i] == A[i-1]) {
				cnt ++;
			} else {
				ans += cnt / 2;
				cnt = 1;
			}
		}
		ans += cnt / 2;
		printf("%d\n", ans);
	}
	return 0;
}