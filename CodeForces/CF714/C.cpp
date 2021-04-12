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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
int dp[10][MAXN];


int main() {
    int T;
    scanf("%d", &T);
    
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= 9; ++i) {
        dp[i][0] = 1;
    }

    
    
    for(int i = 0; i < 10; ++i) {
        int dp_state[10];
        memset(dp_state, 0, sizeof(dp_state));

        for(int j = 0; j < MAXN; ++j) {
            if(j == 0) {
                dp_state[i] = 1;
            } else {
                int old_state[10];
                for(int k = 0; k < 10; ++k) {
                    old_state[k] = dp_state[k];
                    dp_state[k] = 0;
                }

                for(int k = 0; k < 10; ++k) {
                    dp_state[k] += old_state[(k + 9) % 10];
                    dp_state[k] %= MOD;
                }
                dp_state[1] += old_state[9];
                dp_state[1] %= MOD;
            }

            dp[i][j] = 0;
            for(int k = 0; k < 10; ++k) {
                dp[i][j] = (1ll * dp[i][j] + dp_state[k]) % MOD;
            }
        }
    }

    while(T --) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        ll ans = 0;
        while(n) {
            ans = (ans + dp[n % 10][m]) % MOD;
            n /= 10;
        }

        printf("%lld\n", ans);
    }
    return 0;
}  