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

const int N = 2e5 + 5;
int n;
struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int dis[N];

int finalMax = -1;
int finalPoint = -1;
void dfs2(int x, int pre) {
    if(dis[x] > finalMax) {
        finalMax = dis[x];
        finalPoint = x;
    }

    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        dis[to] = dis[x] + 1;
        dfs2(to, x);
    }
}

void dfs(int x, int pre) {
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        dis[to] = dis[x] + 1;
        dfs(to, x);
    }
}

pair<int, int> solve(int x) {
    for(int i = 1; i <= n; ++i) dis[i] = 0;
    dfs(x, x);
    int maxDis = -1; int maxPoint = -1;
    for(int i = 1; i <= n; ++i) {
        if(maxDis < dis[i]) {
            maxPoint = i;
            maxDis = dis[i];
        }
    }
    return MP(maxPoint, maxDis);
}

int main() {
    
    while(~scanf("%d", &n)) {
        int ans = 0;
        vector<pair<int, int> > edge;

        for(int i = 1; i <= n; ++i) head[i] = -1;
        tot = 0;

        for(int i = 1; i < n; ++i) {
            int fr, to;
            scanf("%d %d", &fr, &to);
            edge.push_back({fr, to});
            add(fr, to);
            add(to, fr);
        }

        

        int fr = solve(1).first;
        pair<int, int> tmpReturn = solve(fr);
        int to = tmpReturn.first;
        ans += tmpReturn.second;

        set<int> tag;
        int tmp = to;
        tag.insert(fr); tag.insert(to);
        while(1) {
            int nextPoint = -1;
            for(int i = head[tmp]; ~i; i = E[i].nx) {
                int to = E[i].to;
                if(dis[to] + 1 == dis[tmp]) {
                    nextPoint = to;
                    break;
                }
            }
            tmp = nextPoint;
            if(nextPoint == fr) break;
            tag.insert(nextPoint);
        }

        for(int i = 1; i <= n; ++i) head[i] = -1;
        tot = 0;

        for(auto item : edge) {
            if(!tag.count(item.first) || !tag.count(item.second)) {
                add(item.first, item.second);
                add(item.second, item.first);
            }
        }

        finalMax = -1;
        finalPoint = -1;
        for(int i = 1; i <= n; ++i) dis[i] = 0;
        for(auto item : tag) {
            if(item != fr && item != to) {
                dfs2(item, item);
            }
        }

        ans += finalMax;

        printf("%d\n", ans);
        printf("%d %d %d\n", fr, to, finalPoint);


    }
    return 0;
}