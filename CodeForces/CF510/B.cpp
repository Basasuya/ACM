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
const int N = 1005;
const int INF = 0x3f3f3f3f;

int c[N];
int type[N];

int dp[10];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;

        char seq[10];
        for (int i = 0; i < n; ++i) {
            scanf("%d %s", &c[i], seq);
            int tt = 0;
            for (int j = 0; j < strlen(seq); ++j) {
                tt += 1 << (seq[j] - 'A');
            }
            type[i] = tt;
            //    printf("%d\n", type[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 7; j >= 0; --j) {
                dp[type[i] | j] = min(dp[type[i] | j], c[i] + dp[j]);
            }
        }
        if (dp[7] == INF)
            printf("-1\n");
        else
            printf("%d\n", dp[7]);
    }
    return 0;
}