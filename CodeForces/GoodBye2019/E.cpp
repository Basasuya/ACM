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

const int MAXN = 1e3 + 5;
int X[MAXN], Y[MAXN];
int fa[MAXN];
int has[MAXN];

struct Node{
    int fr, to, nx, dis;
}E[MAXN * MAXN * 2];
int head[MAXN]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

int color[MAXN];


int Find(int x) { return fa[x] == x ? fa[x] : (fa[x] = Find(fa[x])); }

void dfs(int x, int pre) {
    debug(x, pre);
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to =  E[i].to;
        if(to == pre || color[to] != -1) {
            assert(color[x] == color[to] ^ 1);
            continue;
        }
        color[to] = color[x] ^ 1;  
        dfs(to, x);
    }
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            fa[i] = i;
            has[i] = 0;
        }
        map<ll, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &X[i], &Y[i]);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ll dis = 1ll * (X[i] - X[j]) * (X[i] - X[j]) + 1ll * (Y[i] - Y[j]) * (Y[i] - Y[j]);
                mp[dis].push_back(make_pair(i, j));
            }
        }

        for(auto & vc : mp) {
            // debug(vc.first, vc.second);
            if( (int) (vc.second.size()) < 2) continue;
            for(auto it : vc.second) {
                int t1 = it.first; int t2 = it.second;
                int tt1 = Find(t1); int tt2 = Find(t2);
                if(tt1 != tt2) {
                    fa[tt1] = tt2;
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            int t1 = Find(i);
            has[t1] ++; 
        }

        int maxx = -1;
        for(int i = 0; i < n; ++i) {
            maxx = max(maxx, has[i]);
        }



        vector<int> ans;
        if(maxx == n) {
            tot = 0;
            memset(head, -1, sizeof(head)); tot = 0;
            for(auto & vc : mp) {

                if( (int) (vc.second.size()) < 2) continue;
                for(auto it : vc.second) {
                    int t1 = it.first; int t2 = it.second;
                    add(t1, t2);
                    add(t2, t1);
                    debug(t1, t2);
                }
            }

            for(int i = 0; i < n; ++i) {
                color[i] = -1;
            }

            color[0] = 0;
            dfs(0, 0);

            for(int i = 0; i < n; ++i) {
                if(color[i] == 0) ans.push_back(i);
            }

        } else {
            int t1 = Find(0);
            
            for(int i = 0; i < n; ++i) {
                if(Find(i) == t1) {
                    ans.push_back(i);
                }
            }
            
        }

        printf("%d\n", (int) ans.size());
        for(int i = 0, len = ans.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i] + 1);
        }
        printf("\n");

    }
    return 0;
}