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
int n, k, A, B;

ll dfs(int l, int r) {
    int t1 = lower_bound(a, a + k, l) - a;
    int t2 = upper_bound(a, a + k, r) - a;
    int len = t2 - t1;
    // printf("%d %d: %d %d\n", l, r, t1, t2);
    if(len == 0) return A;
    else if(l == r) {
        // printf("%d %d %lld\n", l, r, 1ll * B * len * (r - l + 1));
        return 1ll * B * len * (r - l + 1);
    } else {
        int m = (l + r) >> 1;
        ll tmp = min(1ll * B * len * (r - l + 1),  dfs(l, m) + dfs(m+1, r));
        // printf("%d %d %lld %lld\n", l, r, tmp, 1ll * B * len * (r - l + 1));
        return tmp;
    }
}

int main() {
    
    while(~scanf("%d %d %d %d", &n, &k, &A, &B)) {
        for(int i = 0; i < k; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + k);

        printf("%lld\n", dfs(1, 1<<n));
    }
    return 0;
}