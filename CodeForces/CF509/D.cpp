#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

ll x1[N], x2[N];
int main() {
    int n, h;
    while (~scanf("%d %d", &n, &h)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &x1[i], &x2[i]);
        }

        // if (h == 1) {
        //     ll ans = -1;
        //     for (int i = 1; i <= n; ++i) {
        //         ans = max(ans, x2[i] - x1[i]);
        //     }
        //     printf("%lld\n", ans + 1);
        //     continue;
        // }
        x1[n + 1] = 2000000000;

        ll tmpAns = 0;
        ll tmpLimit = h;
        ll ans = -1;
        ll preLimit, preAns;
        int pos = 1;
        for (int i = 1; i <= n; ++i) {

            // printf("%d\n", pos);
            for (int j = pos + 1; j <= n + 1; ++j) {
                preLimit = tmpLimit;
                preAns = tmpAns;

                tmpLimit -= x1[j] - x2[j - 1];
                tmpAns += x1[j] - x1[j - 1];
                if (tmpLimit <= 0) {
                    pos = j - 1;
                    tmpAns += tmpLimit;
                    break;
                }
            }
            // printf("%lld\n", tmpAns);

            ans = max(tmpAns, ans);

            tmpLimit = preLimit + x1[i + 1] - x2[i];
            tmpAns = preAns - x1[i + 1] + x1[i];
            if (pos == i) {
                tmpAns = 0;
                tmpLimit = h;
                pos = i + 1;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
/*



3 1
2 5
7 9
10 11



9 1
460 6256
12353 14270
15353 17985
20343 21967
24632 28186
30450 36154
42644 43744
48071 49220
148469 157546
*/