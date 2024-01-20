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

const int N = 5e3 + 5; 
ll Mul[N];
ll two[N];
ll prefix[N];
ll Cnm[N][N];

ll Pow(ll x, ll y, int MOD) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll C(int x, int y, int MOD) {
    // debug(x, y);
    if (x < y || y < 0 || x < 0) return 0;
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2, MOD) % MOD;
}

int main() {
    int n, MOD;
    while(~scanf("%d %d", &n, &MOD)) {
        Mul[1] = 1; Mul[0] = 1;
        // two[0] = 1; two[1] = 2;
        for(int i = 2; i < n + 5; ++i) {
            Mul[i] = 1ll * Mul[i - 1] * i % MOD;
            // two[i] = 1ll * two[i - 1] * 2 % MOD; 
        }
        Cnm[0][0] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                Cnm[i][j] = (Cnm[i - 1][j - 1] + Cnm[i - 1][j]) % MOD;
            }
        }

        prefix[0] = Mul[n - 2];
        // prefix[1] = Mul[n - 3];
        for(int i = 1; i <= n - 2; ++i) {
            prefix[i] = 0;
            for(int j = 0; j <= i - 1; ++j) {
                // debug(i - 1, j, n - 3 - j);
                prefix[i] = (prefix[i] + Cnm[i - 1][j] * Mul[n - 3 - j] % MOD) % MOD;
            }
            debug(prefix[i]);
        }

        ll ans = 0;
        // default use 1 as last one
        for(int i = 2; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                int tmp = (n + 1) / 2 + i;
                if (j >= tmp) {
                    // large the half line
                    break;
                }

                int tmpr = n / 2 + j;
                if (tmp <= n + 1 && tmpr >= n + 1) {
                    // debug(i, j);
                    ans = (ans + prefix[j - i]) % MOD;
                }
            }
        }

        printf("%lld\n", ans * n % MOD);
    }
    return 0;
}