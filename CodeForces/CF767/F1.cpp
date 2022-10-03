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

const int N = 1e6 + 5; 
ll Mul[N];
ll two[N];

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
    debug(x, y);
    if (x < y || y < 0 || x < 0) return 0;
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}

int main() {
    Mul[1] = 1; Mul[0] = 1;
    two[0] = 1; two[1] = 2;
    for(int i = 2; i < N; ++i) {
        Mul[i] = 1ll * Mul[i-1] * i % MOD;
        two[i] = 1ll * two[i - 1] * 2 % MOD; 
    }

    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        if(n == m) {
            printf("%lld\n", 1ll * k * n % MOD);
            continue;
        }

        if(m == 0) {
            printf("0\n");
            continue;
        }

        ll ans = 0;
        for(int i = 1; i <= m; ++i) {
            ans = (ans + C(n - i - 1, m - i) * i % MOD * k % MOD * Pow(two[n - i], MOD - 2) % MOD) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}