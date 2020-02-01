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
const int MOD = 998244353;

ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        map<int, int> mp;
        vector<vector<int> > vc;
        for(int i = 0; i < n; ++i) {
            int t; scanf("%d", &t);
            vector<int> tmp;
            for(int j = 0; j < t; ++j) {
                int x; scanf("%d", &x);
                tmp.push_back(x);
                mp[x] ++;
            }
            vc.push_back(tmp);
        }

        debug(mp);

        ll ans = 0;
        ll reciprocalN = Pow(n, MOD - 2);
        for(int i = 0; i < n; ++i) {
            ll reciprocalItem = Pow(vc[i].size(), MOD - 2);
            ll tt = reciprocalItem * reciprocalN % MOD * reciprocalN % MOD;
            for(auto item : vc[i]) {
                ans = (ans + tt * mp[item] % MOD) % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}