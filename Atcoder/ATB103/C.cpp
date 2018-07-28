#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
const int N = 3000;
const ll INF = 1e18;
 
int a[N];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i] - 1;
		}
		printf("%d\n", sum);
	}
	return 0;
}