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

const int N = 1e4 + 5;
int mp[105][105];
int dir[4][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };


struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to, int dis) {
    E[tot].to = to; E[tot].nx = head[fr]; E[tot].dis = dis; head[fr] = tot ++;
}


struct Hode{
    int po, di;
    Hode(int a=0, int b=0):po(a), di(b){}
    bool operator < (const Hode & T) const {
        return di > T.di;
    }
};

int dis[N], vis[N];
void dij1(int s) {
    priority_queue<Hode> Q;
    memset(dis, INF, sizeof(dis));
    dis[s] = 0; 
    memset(vis, 0, sizeof(vis));
    Q.push(Hode(s, dis[s]));

    while(!Q.empty()) {
        int po = Q.top().po; Q.pop();
        if(vis[po]) continue;
        vis[po] =  1;
        for(int i = head[po]; ~i; i = E[i].nx) {
            int to = E[i].to;
            if(dis[to] > dis[po] + E[i].dis) {
                dis[to] = dis[po] + E[i].dis;
                Q.push(Hode(to, dis[to]));
            }
        }
    }
}

int main() {
    int  T;
    scanf("%d", &T);
    while(T --) {
        memset(head, -1, sizeof(head));
        tot = 0;

        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }


        for(int xx = 0; xx < n; ++xx) {
            for(int yy = 0; yy < n; ++yy) {
                for(int i = 0; i < 4; ++i) {
                    for(int j = 1; j <= k; ++j) {
                        int tx = xx + dir[i][0] * j; int ty = yy + dir[i][1] * j; 
                        if(tx >= 0 && tx < n && ty >= 0 && ty < n && mp[tx][ty] > mp[xx][yy]) {
                            add(xx * n + yy, tx * n + ty, mp[tx][ty]);
                        }
                    }
                }
            }
        }
        

        dij1(0);
        int ans = 0;
        for(int xx = 0; xx < n; ++xx) {
            for(int yy = 0; yy < n; ++yy) {
                debug(xx, yy, dis[xx * n + yy]);
                if(dis[xx * n + yy] != INF) ans = max(ans, dis[xx * n + yy]);
            }
        }

        printf("%d\n", ans + mp[0][0]);
    }
    return 0;
}


/*


100
3 1
1 2 5
10 11 6
12 12 7
*/