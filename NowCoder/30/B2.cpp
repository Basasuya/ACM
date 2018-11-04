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
const int N = 1e3+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int mp[N][N];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(mp, INF, sizeof(mp));
        for(int i = 1; i <= n; ++i) mp[i][i] = 0;
        for(int i = 1; i < n; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            mp[a][b] = c;
            mp[b][a] = c;
        }

        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        // for(int i = 1; i <= n; ++i) {
        //     for(int j = 1; j <= n; ++j) {
        //         printf("%d ", mp[i][j]);
        //     }
        //     printf("\n");
        // }

        int ans = 0;
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if( (mp[i][j] % 2) == (mp[i][k] % 2)  && (mp[i][k] % 2) == (mp[j][k] % 2) ) {
                        ans ++;
                        if(i <= j && j <= k) printf("%d %d %d\n", i, j, k);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

/*

3
1 2 2
1 3 4
3
1 2 2
1 3 4

6
1 2 3
1 3 4
2 4 5
2 5 8
3 6 10
*/