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

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

ll Mul[MAXN];
ll Two[MAXN];
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll C(int x, int y) {
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(1ll * Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}


int main() {

    Mul[0] = Mul[1] = 1;
    Two[0] = 1;
    Two[1] = 2;
    for(int i = 2; i < MAXN; ++i) {
        Mul[i] = 1ll * Mul[i - 1] * i % MOD;
        Two[i] = 1ll * Two[i - 1] * 2 % MOD;
    }

    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        
        if(n == 2) {
            printf("0\n");
            continue;
        }

        ll ans = 0;
        for(int i = m; i >= 1; --i) {
            if(i - 1 >= n - 2) ans = (ans + 1ll * C(i - 1, n - 2) * (n - 2) % MOD * Two[n - 3] % MOD ) % MOD;
            else break;
        }


        printf("%lld\n", ans);
    }
    return 0;
}