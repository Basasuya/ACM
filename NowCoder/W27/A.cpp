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
// const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int A[M];
int has[M];

int tot;
int square[M];

int main() {
    int n;
    tot = 0;
    for(int i = 1; ; ++i) {
        int tt = i * i;
        if(tt > 2e5) break;
        square[tot ++] = i * i;
    }
    while(~scanf("%d", &n)) {
        memset(has, 0, sizeof(has));
        int maxx = -1;
        ll ans = 0;
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        for(int i = 0; i < n; ++i) {
            int pos = upper_bound(square, square + tot, A[i]) - square;
            for(int j = pos; j < tot; ++j) {
                int tt = square[j] - A[i];
                // printf("%d\n", tt);
                if(tt > maxx) break;
                ans += has[tt];
            }
            has[A[i]] ++;
            maxx = max(maxx, A[i]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}