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

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        vector<ll> vc(n + 5, 0);
        for(int i = 0; i < m; ++i) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            vc[a] += d;
            vc[b] -= d;
        }

        queue<pair<int, ll>> pos;
        queue<pair<int, ll>> neg;
        vector<tuple<int, int, ll> > ans;
        for(int i = 1; i <= n; ++i) {
            if(vc[i] > 0) {
                pos.push({i, vc[i]});
            } else if(vc[i] < 0) neg.push({i, -vc[i]});
        }

        while(!pos.empty() && !neg.empty()) {
            auto t1 = pos.front(); pos.pop();
            auto t2 = neg.front(); neg.pop();

            if(t1.second != t2.second) {
                // ans.push_back({t1.first, t2.first, min(t1.second, t2.second)});
                if(t1.second > t2.second) pos.push({t1.first, t1.second - min(t1.second, t2.second)});
                else neg.push({t2.first, t2.second - min(t1.second, t2.second)});
            } 
            ans.push_back({t1.first, t2.first, min(t1.second, t2.second)});
        }



        printf("%d\n", (int)ans.size());
        for(int i = 0, len = ans.size(); i < len; ++i) {
            printf("%d %d %lld\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
        }
    }
    return 0;
}