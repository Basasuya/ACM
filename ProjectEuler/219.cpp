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

int dp[15];
int main() {
    int a, b;
    int T;
    ll n;
    scanf("%d", &T);
    while(T --) {
        // priority_queue<ll, vector<ll>,greater<ll> > Q;
        memset(dp, 0, sizeof(dp));
        scanf("%lld %d %d", &n, &a, &b);
        ll ans = 0;

        dp[a] = 1;
        dp[b] = 1;
        while(ans < ) {

        }

        printf("%lld\n", ans);
    }
    return 0;
}