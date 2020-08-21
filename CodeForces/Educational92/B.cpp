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

const int MAXN = 3e5 + 5;
int A[MAXN];
int dp[MAXN][6];

int result;
void dfs(int pos, int K, int Z, int ans, bool not_left) {
    if(result < ans) {
        result = ans;
    }

    if(dp[pos][Z] < ans) {
        dp[pos][Z] = ans;
    } else return;

    if(K == 0) return;

    if(pos && !not_left && Z) {
        dfs(pos - 1, K - 1, Z - 1, ans + A[pos - 1], true);
    }

    dfs(pos + 1, K - 1, Z, ans + A[pos + 1], false);


}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        
        int n, k, z;
        scanf("%d %d %d", &n, &k, &z);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            memset(dp[i], -1, sizeof(dp[i]));
        }
        result = -1;

        dfs(0, k, z, A[0], false);

        printf("%d\n", result);
    }
    return 0;
}