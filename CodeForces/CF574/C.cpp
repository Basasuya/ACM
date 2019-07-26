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

const int MAXN = 1e5 + 5;
int h[MAXN][2];
ll dp[MAXN][2];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &h[i][0]);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &h[i][1]);
        }

        dp[0][0] = dp[0][1] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + h[i][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + h[i][1]);
        }

        printf("%lld\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}