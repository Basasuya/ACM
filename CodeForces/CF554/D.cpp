#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1005;
ll dp[N][N][2];

ll dfs(int l, int r, int pre) {
    if(l == 0) return (r - pre) / 2;
    if(dp[l][r][pre] != -1) return dp[l][r][pre];
    ll result = -1;

    if(pre == 0) {
        if(l == r) gmax(result, max(dfs(l - 1, r, 0), dfs(l-1, r, 1) + 1));
        else gmax(result, max(dfs(l - 1, r, 0), dfs(l - 1, r, 1) + 1) + max(dfs(l, r - 1, 0), dfs(l, r - 1, 1) + 1) );
    } else {
        if(l == r) gmax(result, dfs(l - 1, r, 0));
        else gmax(result, dfs(l - 1, r, 0) + dfs(l, r - 1, 0));
    }
    result %= MOD;
    // printf("%d %d %d\n", l, r, result);

    dp[l][r][pre] = result;
    return result;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        ll result = dfs(n, n, 0);

        printf("%lld\n", result); 
    }
    return 0;
}