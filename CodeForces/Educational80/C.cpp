#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MP make_pair
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define bitCount(a)  __builtin_popcount(a)
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
const int INF = 0x3f3f3f3f;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MOD = 1e9 + 7;

int dp[2][1005];
// int preSum[1005];

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        if(m == 1) {
            printf("%lld\n", 1ll * n * (n + 1) / 2);
            continue;
        }

        // memset(dp, -1, sizeof(dp));
        int fl = 0;
        for(int i = 0; i < m; ++i) {
            if(i == 0) {
                for(int j = 1; j <= n; ++j) {
                    dp[fl ^ 1][j] = 1;
                }
                fl ^= 1;
            } else {
                for(int j = 0; j <= n; ++j) {
                    dp[fl ^ 1][j] = 0;
                }
                for(int j = 1; j <= n; ++j) {
                    dp[fl ^ 1][j] = (dp[fl ^ 1][j - 1] + dp[fl][j]) % MOD;
                }
                fl ^= 1;
            }
        }

        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                ans = (ans + 1ll * dp[fl][i] * dp[fl][n - j + 1] % MOD) % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}