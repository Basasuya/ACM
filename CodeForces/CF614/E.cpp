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

const int MAXN = 3e3 + 5;
struct Node{
    int fr, to, nx, dis;
}E[MAXN << 1];

int par[MAXN][MAXN];
int son[MAXN][MAXN];
ll dp[MAXN][MAXN];

int head[MAXN]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

void dfs(int x, int pre, int root) {
    par[x][root] = pre;
    son[x][root] = 1;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        dfs(to, x, root);
        son[x][root] += son[to][root];
    }
}

ll getDp(int x, int y) {
    if(x == y) return 0;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 1ll * son[x][y] * son[y][x] + max(getDp(par[x][y], y), getDp(par[y][x], x));

    return dp[x][y];
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(head, -1, sizeof(head));
        tot = 0;
        for(int i = 1; i < n; ++i) {
            int fr, to; scanf("%d %d", &fr, &to);
            add(fr, to);
            add(to, fr);
        }   

        memset(par, 0, sizeof(par));
        memset(son, 0, sizeof(son));
        memset(dp, -1, sizeof(dp));

        for(int i = 1; i <= n; ++i) {
            dfs(i,i,i);
        }

        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                ans = max(ans, getDp(i, j));
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}