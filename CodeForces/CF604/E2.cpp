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
ll p[MAXN];
ll preMul[MAXN];
ll preSum[MAXN];
int n, q;
const int MOD = 998244353;

ll origin;
ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll get(int fr, int to) {
    if(fr == 1 && to == n) return origin;

    ll B = preMul[to] * Pow(preMul[fr - 1], MOD - 2) % MOD;
    ll A = ( (preSum[to - 1] - preSum[fr - 1] + MOD) % MOD * Pow(preMul[fr - 1], MOD - 2) % MOD + 1)% MOD;
    return A * Pow(B, MOD - 2) % MOD; 
}
int main() {
    
    while(~scanf("%d %d", &n, &q)) {
        ll inv_100 = Pow(100, MOD - 2);

        ll ans = 1;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &p[i]);
            p[i] = 1ll * p[i] * inv_100 % MOD;
        }

        preMul[0] = 1;
        for(int i = 1; i <= n; ++i) {
            preMul[i] = preMul[i-1] * p[i] % MOD;             
        }

        preSum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            preSum[i] = (preSum[i-1] + preMul[i]) % MOD;
        } 
        // preSum[0] = MOD - 1;

        ans = (preSum[n-1] + 1) % MOD * Pow(preMul[n], MOD - 2) % MOD;
        origin = ans;
        debug(ans);

        set<int> st;
        st.insert(1);
        st.insert(n + 1);
        for(int i = 0; i < q; ++i) {
            int x;
            scanf("%d", &x);
            int fr = *(--st.lower_bound(x));
            int to = *(st.upper_bound(x));

            debug(fr, to);
            if(!st.count(x)) {
                ans = ans - get(fr, to-1) + get(fr, x-1) + get(x, to-1) + MOD;
                ans %= MOD;
                st.insert(x);
            } else {
                ans = ans + get(fr, to-1) - get(fr, x-1) - get(x, to-1) + 2 * MOD;
                ans %= MOD;
                st.erase(x);
            }

            printf("%lld\n", ans);
        }

    }
    return 0;
}


/*


5 5
10 20 30 40 50
2
3
4
5
3


*/