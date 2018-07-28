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
 
int main() {
	int a[3];
	while(~scanf("%d %d %d", &a[0], &a[1], &a[2])) {
		sort(a, a+3);
		printf("%d\n", a[2] - a[0]);
	}
	return 0;
}