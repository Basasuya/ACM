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
#define forw(i, l, r) for (int i = l; i < r; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
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

const int MAXN = 2e5 + 5;
ll dp[MAXN][2];
char seq[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", seq + 1);

        dp[0][0] = 0;
        dp[0][1] = 1e18;
        for(int i = 1; i <= n; ++i) {
            int tmp = (seq[i] - '0') | (seq[i + 1] - '0');
            // debug(tmp);
            dp[i][0] = tmp == 1 ? 1e18 : min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
            dp[i][1] = min(dp[i - 1][0] + 2 * a + 2 * b, dp[i - 1][1] + a + 2 * b);

        }
        // for(int i = 1; i <= n; ++i) {
        //     debug(dp[i][0], dp[i][1]);
        // }

        printf("%lld\n", dp[n][0] + b);
    }
    return 0;
}