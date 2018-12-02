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

int ok[N];
int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        memset(ok, 0, sizeof(ok));

        ll ans = 0;
        if(n < k) {
            for(int i = 0; i < k; ++i) {
                ans = (ans * 2 + 1) % MOD;  
            }
            printf("%lld\n", ans);
            continue;
        }

        ok[0] = 1;
        for(int i = n/2 - k/2 + 1; i < n/2; ++i) {
            ok[i] = 1;
        }
        for(int i = n/2; i < n/2 + k/2 - 1; ++i) {
            ok[i] = 1;
        }
        ok[n - 1] = 1;

        for(int i = 0; i < n; ++i) {
            ans = (ans * 2 + ok[i]) % MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}