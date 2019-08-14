#include <iostream>
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
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

const int INF = 0x3f3f3f3f;
const int MAXN = 2550;
struct Node{
    int fr, to, nx; ll dis;
}E[MAXN << 2];
int n, m, p;
int vis[MAXN];
int head[MAXN]; int tot = 0;
ll dis[MAXN];
void add(int fr, int to, int dis) {
    E[tot].fr = fr; E[tot].to = to; E[tot].dis = dis; E[tot].nx = head[fr]; head[fr] = tot ++;
}


bool bellman_ford() {
    for (int i = 0; i <= n; i++) dis[i] = 1e18;  //初始化
    dis[1] = 0;
    bool ok;     
    ll tmp;                                     //判断是否发生了松弛
    for (int i = 1; i <= 2 * n; i++) {
        ok = false;
        for (int j = 0; j < tot; j++) {
            if (dis[E[j].fr] + E[j].dis < dis[E[j].to]) {
                dis[E[j].to] = dis[E[j].fr] + E[j].dis;
                ok = true;
            }
        }
        if (!ok)  //没有发生松弛，及时退出
            break;
        if(i <= n) {
            tmp = dis[n];
        }
    }
    if(dis[n] != tmp) return false; 
    // for (int i = 0; i < tot; i++)                                 //寻找负权回路
    //     if (dis[E[i].fr] + E[i].dis < dis[E[i].to]) return false;  //存在负权回路
    return true;
}

int main() {
    
    while(~scanf("%d %d %d", &n, &m, &p)) {
        tot = 0;
        memset(head, -1, sizeof(head));

        for(int i = 0; i < m; ++i) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            add(a, b, -c + p);
        }

        bool suc = bellman_ford();
        if(!suc) printf("-1\n");
        else printf("%lld\n", max(1ll * 0, -dis[n]));
        
    }
    return 0;
}