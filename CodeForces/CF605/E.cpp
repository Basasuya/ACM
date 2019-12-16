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
#define mp make_pair
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

int n;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int A[MAXN];
int dp[MAXN];
int has[MAXN];
int dfs(int x, int pre) {
    debug(x, pre, dp[x]);
    if(dp[x] != -INF) return dp[x];

    int ans = INF;
    if(x - A[x] >= 1 && x - A[x] != pre) {
        if(A[x - A[x]] % 2 != A[x] % 2) ans = min(ans, 1);
        else if(!has[x - A[x]]) {
            has[x - A[x]] = 1;
            ans = min(ans, dfs(x - A[x], x) + 1);
            has[x - A[x]] = 0;
        }
    }

    if(x + A[x] <= n && x + A[x] != pre) {
        if(A[x + A[x]] % 2 != A[x] % 2) ans = min(ans, 1);
        else if(!has[x + A[x]]) {
            has[x + A[x]] = 1;
            ans = min(ans, dfs(x + A[x], x) + 1);
            has[x + A[x]] = 0;
        }
    }
    dp[x] = ans;
    debug("set", x, ans);
    return ans;
}
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
            dp[i] = -INF;
        }
        for(int i = 1; i <= n; ++i) {
            if(dp[i] == -INF) {
                has[i] = 1;
                dp[i] = dfs(i, i); 
                has[i] = 0;
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(i != 1) printf(" ");
            if(dp[i] == INF) printf("-1");
            else printf("%d", dp[i]);
        }
        printf("\n");
    }
    return 0;
}