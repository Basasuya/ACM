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

ll solve(ll x) {
    for(ll i = 1; i <= x + 1; ++i) {
        if(x % i != 0) {
            return i;
        }
    }
    return -1;
}
int main() {
    // ll maxx = -1;
    // for(ll i = 1; i <= 1e16; ++i) {
    //     ll ans = solve(i);
    //     maxx = max(maxx, ans);
    //     if(i % 100000 == 0) {
    //         debug(i, maxx);
    //     }
    //     // if(ans > 5) printf("%lld %lld\n", i, solve(i));
    // }
    // debug(maxx);

    int T;
    scanf("%d", &T);
    while(T --) {
        ll ans = 0;

        ll n;
        scanf("%lld", &n);

        vector<int> vc;
        int pre = 0; ll mul = 1;

        for(int i = 2; i <= 100; ++i) {
            int tmp = i;
            for(auto x : vc) {
                if(tmp % x == 0) {
                    tmp /= x;
                }
            }

            // debug(vc);
            
            if(tmp != 1) {
                vc.push_back(tmp);
                if(mul > n) break;
                ans = (ans + 1ll * (n / mul) * (i - pre) % MOD) % MOD;
                pre = i;
                mul *= tmp;
            } 
        }

        printf("%lld\n", ans);
    }
    return 0;
}