#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

int a[N];
int main() {
    int n, k, m;
    while(~scanf("%d %d %d", &n, &k, &m)) {
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        double ans = -1;
        for(int i = 0; i < min(m+1, n); ++i) {
            ans = max(ans, (sum + min(1ll * (m - i), 1ll * (n - i) * k))*1.0 / (n - i) );
            sum -= a[i];
            // printf("%lld %.3f\n", sum, ans);
        }

        printf("%.9f\n", ans);
    }
    return 0;
}