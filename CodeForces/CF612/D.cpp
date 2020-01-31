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

const int MAXN = 2e3 + 5;        
struct Node{
    int fr, to, nx, dis;
}E[MAXN << 1];
int head[MAXN]; int tot = 0;
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

int cost[MAXN];
// int son[MAXN];
int val[MAXN];
vector<vector<int> > vc;
bool suc = true;

void dfs(int x) {
    if(suc == false) return;
    // son[x] = 1;
    int cnt = 0;
    if(cost[x] == 0) vc[x].push_back(x);
    for(int i = head[x]; ~i && suc; i = E[i].nx) {
        int to = E[i].to;
        dfs(to);
        // son[x] += son[to];
        
        for(auto& item : vc[to]) {
            // for(auto item : li) {
                vc[x].push_back(item);
                cnt ++;
                if(cnt == cost[x]) vc[x].push_back(x);
            // }
        }
    }
    
    if(cnt < cost[x]) suc = false;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(head, -1, sizeof(head));
        tot = 0;
        vc.clear();
        for(int i = 0; i <= n; ++i) {
            vc.push_back(vector<int>());
        }
        int root;
        for(int i = 1; i <= n; ++i) {
            int p;
            scanf("%d %d", &p, &cost[i]);
            add(p, i);
            if(p == 0) root = i;
        }

        dfs(root);
        
        if(suc == false) {
            printf("NO\n");
            continue;
        }

        for(int i = 0, len = vc[root].size(); i < len; ++i) {
            val[vc[root][i]] = i + 1;
        }

        printf("YES\n");
        for(int i = 1; i <= n; ++i) {
            if(i != 1) printf(" ");
            printf("%d", val[i]);
        }
        printf("\n");
    }
    return 0;
}