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

const int MAXN = 2e5 + 5;
int special[MAXN];
int A[MAXN];

struct Node{
    int to, nx;
}E[MAXN << 1];
int head[MAXN]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

int vis[MAXN];
int disToSt[MAXN];
int disToEnd[MAXN];
int main() {
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        memset(head, -1, sizeof(head));
        tot = 0;
        memset(special, 0, sizeof(special));

        for(int i = 0; i < k; ++i) {
            int x; scanf("%d", &x);
            A[i] = x;
            special[x] = 1;
        }

        bool suc = false;
        for(int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            if(special[a] && special[b]) { suc = true; }
            add(a, b); add(b, a); 
        }
        int st = 1; int ed = n;

        queue<int> Q;
        memset(vis, 0, sizeof(vis));
        vis[st] = 1;
        disToSt[st] = 0;
        Q.push(st);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            debug(x);
            for(int i = head[x]; ~i; i = E[i].nx) {
                int to = E[i].to;
                if(vis[to]) continue;
                vis[to] = 1;
                disToSt[to] = disToSt[x] + 1;
                Q.push(to);
            }
        }
        int ans = disToSt[ed];
        debug(suc);
        if(suc == true) {
            printf("%d\n", ans);
            continue;
        }

        while(!Q.empty()) Q.pop();
        memset(vis, 0, sizeof(vis));
        vis[ed] = 1;
        disToEnd[ed] = 0;
        Q.push(ed);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i = head[x]; ~i; i = E[i].nx) {
                int to = E[i].to;
                if(vis[to]) continue;
                vis[to] = 1;
                disToEnd[to] = disToEnd[x] + 1;
                Q.push(to);
            }
        }

        for(int i = 1; i <= n; ++i) debug(i, disToSt[i], disToEnd[i]);

        int maxx = -1;
        vector<tuple<int, int, int> >  vc;
        for(int i = 0; i < k; ++i) {
            vc.push_back({disToSt[A[i]], disToEnd[A[i]], i});
        }

        auto cmp = [](tuple<int, int, int> A, tuple<int, int, int> B) { return get<0>(A) < get<0>(B); };
        sort(vc.begin(), vc.end(), cmp);
        
        // if(n == 99998) {
        //     for(int i = 0; i < k; ++i) {
        //         printf("%d %d %d\n", get<0>(vc[i]), get<1>(vc[i]), get<2>(vc[i]));
        //     }
        // }
        // debug(sortStDis, sortEdDis);
        int pre = k; int dis = -1;
        int tmpAns = -1;
        for(int i = k-1; i >= 0; --i) {
            if(i != k-1 && get<0>(vc[i]) == get<0>(vc[i + 1]) ) {
                suc = true;
                break;
            }

            // if(i != k-1 && get<0>(vc[i]) != get<0>(vc[i + 1]) ) {
            //     for(int j = i + 1; j < pre; ++j) {
                    
            //     }
            //     pre = i;
            // }
            if(dis != -1) {
                tmpAns = max(tmpAns, get<0>(vc[i]) + dis + 1);
            }

            dis = max(dis, get<1>(vc[i]));
        }

        if(suc == true) {
            // printf("hhhhh\n");
            printf("%d\n", disToSt[ed]);
            continue;
        }

        if(tmpAns == -1) tmpAns = INF; 
        // if(n == 99998) printf("hhh %d\n", disToSt[ed]);
        printf("%d\n", min(tmpAns, ans));


    }
    return 0;
}