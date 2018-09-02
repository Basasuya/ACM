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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
typedef long long ll;

int n, k;
int x[N];
int Abs(int x) {
    return x < 0 ? -x : x;
}
int main() {
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
        }

        int ans = INF;
        for(int i = 1; i <= n-k + 1; ++i) {
            if(x[i] <= 0 && x[i + k - 1] >= 0) {
                ans = min(ans, min(-x[i], x[i+k-1]) + x[i+k-1] - x[i]);
            } else {
                ans = min(ans, max(Abs(x[i]), Abs(x[i + k - 1])));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
