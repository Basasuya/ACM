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

const int MAXN = 1e3 + 5;
int B[MAXN];
int C[MAXN];
int dp[MAXN];
int pack[20005];

int main() {
    memset(dp, INF, sizeof(dp));
    dp[1] = 0;
    for(int i = 1; i < MAXN; ++i) {
        for(int j = 1; j <= i; ++j) {
            int edge = i + i / j;
            if(edge < MAXN) dp[edge] = min(dp[edge], dp[i] + 1);
        }
    }
    // int maxx = -1;
    // for(int i = 1; i < MAXN; ++i) {
    //     maxx = max(maxx, dp[i]);
    // }
    // debug(maxx);

    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d %d", &n, &k);

        int all_cost = 0; int all_ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &B[i]);
            // debug(dp[B[i]]);
            all_cost += dp[B[i]];
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &C[i]);
            all_ans += C[i];
        }

        if(k == 0) {
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                if(B[i] == 1) ans += C[i];
            }
            printf("%d\n", ans);
            continue;
        }

        if(k >= all_cost) {
            printf("%d\n", all_ans);
            continue;
        }

        for(int i = 0; i <= k; ++i) {
            pack[i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = k, cost = dp[B[i]]; j >= cost; --j) {
                pack[j] = max(pack[j], pack[j - cost] + C[i]);
            }
        }
        
        int maxx = -1;
        for(int i = 0; i <= k; ++i) {
            maxx = max(maxx, pack[i]);
        }


        printf("%d\n", maxx);
    }
    return 0;
}