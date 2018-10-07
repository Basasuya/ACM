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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int n, T;
    while(~scanf("%d %d", &n, &T)) {
        int ans = INF;
        for(int i = 0; i < n; ++i) {
            int c, t;
            scanf("%d %d", &c, &t);
            if(t <= T) {
                ans = min(ans, c);
            }
        }

        if(ans == INF) printf("TLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}