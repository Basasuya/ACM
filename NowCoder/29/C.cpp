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
const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b > a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b < a)a = b; }
#define MS(x, y) memset(x, y, sizeof(x))

ll sum[N];
int a[N];
int has[N];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(has, 0, sizeof(has));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            has[a[i]] ++;
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = i, cnt = 1; j <= m; j += i, cnt ++) {
                sum[j] += 1ll * has[i];
            }
        }
        for(int i = 1; i <= m; ++i) {
            sum[i] += sum[i-1];
            has[i] += has[i-1];
        }
        // for(int i = 1; i <= n; ++i) sum[i] += sum[i-1];
        // for(int i = 1; i <= n; ++i) printf("%d ", sum[i]); printf("\n");
        for(int i = 1; i <= m; ++i) {
            for(int j = i, cnt = 1; j <= m; j += i, cnt ++) {
                sum[i] += 1ll * cnt * ( has[min(m, i + j -1)]- has[j-1] );
            }
        }
        ll ans = 0;
        // for(int i = 1; i <= n; ++i) printf("%d ", sum[i]); printf("\n");
        for(int i = 1; i <= m; ++i) {
            ans ^= sum[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}