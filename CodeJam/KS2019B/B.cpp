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

const int N = 1e4 + 5;

int S[105], E[105], L[105], id[105];
ll dp[2][N];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        memset(dp, 0, sizeof(dp));

        int n; scanf("%d", &n);
        int sumE = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &S[i], &E[i], &L[i]);
            sumE += S[i];
            id[i] = i;
        }
        sort(id, id + n, [&](int x, int y) { return 1ll * S[x] * L[y] < 1ll * S[y] * L[x]; });

        int fl = 0;
        for(int i = 0; i < n; ++i) {
            int x = id[i];
            for(int j = 0; j <= sumE; ++j) {
                gmax(dp[fl ^ 1][min(sumE, j + S[x])], dp[fl][j] + max(0ll, E[x] - 1ll * j * L[x]));
            }
            for(int j = 0; j <= sumE; ++j) {
                gmax(dp[fl ^ 1][j], dp[fl][j]);
                // dp[fl][j] = 0;
            }
            // memset(dp[fl], 0, sizeof(dp[fl]));
            fl ^= 1;
        }

        ll ans = -1;
        for(int i = 0; i <= sumE; ++i) {
            ans = max(ans, dp[fl][i]);
        }

        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}

/*


3
4
20 10 1
5 30 5
100 30 1
5 80 60
3
10 4 1000
10 3 1000
10 8 1000
2
12 300 50
5 200 0
*/