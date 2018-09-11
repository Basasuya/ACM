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
typedef long long ll;
const int N = 2e5+5;

ll prefix[N];
int main() {
    prefix[0] = 0;
    prefix[1] = 1;
    for(int i = 2; i < N; ++i) {
        prefix[i] = prefix[i-1] + i;
    }
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        int stNum = (k % 2 == 0) ? k/2 : k;
        int foot = (k % 2 == 0) ? k/2 : k;
        ll ans = 0;
        for(int i = stNum; i <= n; i += foot) {
            int t1 = n / k;
            if( (k % 2 == 0) && (i % k) ) {
                t1 = (n + k/2) / k;
            }
            ans += 1ll * t1 * t1;
        }

        printf("%lld\n", ans);
    }
    return 0;
}