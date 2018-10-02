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
typedef long long ll;
const int N = 5e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

ll n, p;

ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x;
        x = 1ll * x * x;
        y >>= 1;
    }
    return ans;
}
int solve(ll mid) {
    ll t1 = Pow(p, mid);
    return n % t1 == 0;
}
int main() {
    
    while(~scanf("%lld %lld", &n, &p)) {
        int l = 1; int r = log(n) / log(p) + 1;

        printf("%d\n", r);
        while(l < r) {
            int mid = (l + r) >> 1;
            if(solve(mid)) l = mid + 1;
            else r = mid - 1;
        }

        printf("%d\n", l - 1);
    }
    return 0;
}