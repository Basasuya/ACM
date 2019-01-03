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
const int N = 2e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

char seq[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        
        ll ans = 1;
        int st = n - 1, ed = 0;

        ans ++;
        for(int i = 1; i < n - 1; ++i) {
            if(seq[i] != seq[i-1]) {
                st = i; break;
            } else ans ++;
        }

        ans ++;
        for(int i = n - 2; i >= 1; --i) {
            if(seq[i] != seq[i + 1]) {
                ed = i; break;
            } else ans ++;
        }

        // printf("%lld %d %d\n", ans, st, ed);

        
        if(seq[0] == seq[n - 1]) {
            for(int i = 1; i <= min(st, n - 1) ; ++i) {
                ans = (ans + n - max(i, ed) - 1) % MOD;
                // printf("%lld\n", ans);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}