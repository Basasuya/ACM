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

vector<int> ans;


void dfs(int n, int floor, ll fr, ll to, ll l, ll r) {
    debug(n, floor, fr, to, l, r);
    int start = (n - floor) * 2;
    if(fr > r || fr > to) return;

    ll newTo = fr + start - 1;
    debug(newTo);
    // if( max(l, fr) < ) {
        for(ll i = max(l, fr), end = min(r, newTo); i <= end; ++i) {
            if( (i - fr) % 2 == 0) ans.push_back(floor);
            else ans.push_back((i - fr + 1) / 2 + floor);
        }
    // }
    debug(ans);

    dfs(n, floor + 1, newTo + 1, to, l, r);
    
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n; ll l, r;
        scanf("%d %lld %lld", &n, &l, &r);
        ans.clear();
        dfs(n, 1, 1, 1ll * n * (n - 1), l, r);
        if(r == 1ll * n * (n - 1) + 1) ans.push_back(1);

        for(int i = 0, len = ans.size(); i < len; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        
    }
    return 0;
}