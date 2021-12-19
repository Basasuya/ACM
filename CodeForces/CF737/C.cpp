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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
ll Mul[N];

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
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}

int main() {
    int T;
    scanf("%d",&T);

    Mul[1] = 1; Mul[0] = 1;
    for(int i = 2; i < N; ++i) {
        Mul[i] = 1ll* Mul[i-1] * i % MOD;
    }

    while(T --) {
        int n, k;
        scanf("%d %d", &n, &k);

        if(k == 0) {
            printf("1\n");
            continue;
        }

        // ll odd = 0;
        // for(int i = 1; i <= n; i += 2) {
        //     odd = (odd + C(n, i)) % MOD;
        // }

        ll even = 0;
        for(int i = 0; i <= n; i += 2) {
            even = (even + C(n, i)) % MOD;
        }

        int all = Pow(2, n);

        debug(even);

        ll ans = 0;
        ll tmp = 1;
        for(int i = 1; i <= k; ++i) {
            if(n % 2) {
                tmp = (even + 1) * tmp % MOD;
            } else {
                ans = (ans + tmp * Pow(all, k - i) % MOD) % MOD;
                tmp = (even - 1 + MOD) * tmp % MOD;
            }
            
            if(i == k) {
                ans = (ans + tmp) % MOD;
            }
            debug(ans, tmp);
        }

        printf("%lld\n", ans);
    }
    return 0;
}