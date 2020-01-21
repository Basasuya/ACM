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

int main() {
    ll x0, y0, ax, ay, bx, by;
    ll xs, ys, t;
    while(~scanf("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by)) {
        scanf("%lld %lld %lld", &xs, &ys, &t);

        vector<pair<ll, ll> > vc;
        while(x0 <= xs + t && y0 <= ys + t) {
            // debug("yingyingying");
            if(x0 >= xs - t && y0 >= ys - t) {
                vc.push_back(MP(x0, y0));
            }
            x0 = ax * x0 + bx;
            y0 = ay * y0 + by;
        }

        // debug(vc);

        int ans = 0;
        int n = vc.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                ll dis = min( abs(vc[j].first - xs) + abs(vc[j].second - ys), abs(vc[i].first - xs) + abs(vc[i].second - ys) ) + (vc[j].first - vc[i].first) + (vc[j].second - vc[i].second);

                if(dis <= t) ans = max(ans, j - i + 1);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}