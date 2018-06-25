#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5+5;


int A[N];
int nextNotOne[N];
int main() {
	int n, k;
	while(~scanf("%d %d", &n, &k)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for(int i = n, next = n+1; i >= 1; --i) {
			nextNotOne[i] = next;
			if(A[i] != 1) next = i;
		}
	//	for(int i = 1; i <= n; ++i) printf("%d ", nextNotOne[i]); printf("\n");
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			ll sum = 0, mul = 1;
			for(int j = i; j <= n; sum += nextNotOne[j] - j - 1, j = nextNotOne[j]) {
				ll premul = mul;
				if(2e18 / A[j] < mul) break;
				sum += A[j];
				mul *= A[j];
				int nxPos = nextNotOne[j];
				if(mul % k == 0 && mul/k >= sum && mul/k <= sum + nxPos - j - 1) {
					ans ++;
				}
				
			}
			
		}

		printf("%d\n", ans);
	}
	return 0;
}
