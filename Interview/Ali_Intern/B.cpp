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

char seq[505][505];
int dp[505][505][6];
int dir[4][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };
int n, m;

void bfs(int x, int y, int ex, int ey) {
    memset(dp, INF, sizeof(dp));
    dp[x][y][0] = 0;
    queue<tuple<int, int, int> > Q;
    Q.push(make_tuple(x, y, 0));

    while(!Q.empty()) {
        auto tt = Q.front(); Q.pop();
        int tx = get<0>(tt);
        int ty = get<1>(tt);
        int hasJump = get<2>(tt);
        // debug(tx, tyd, hasJump, dp[tx][ty][hasJump]);
        if(tx == ex && ty == ey) break;
        
        
        for(int i = 0; i < 4; ++i) {
            int xx = tx + dir[i][0]; int yy = ty + dir[i][1]; 
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && seq[xx][yy] != '#' && dp[xx][yy][hasJump] > dp[tx][ty][hasJump] + 1) {
                dp[xx][yy][hasJump] = dp[tx][ty][hasJump] + 1;
                Q.push(make_tuple(xx, yy, hasJump));
            }
        }

        int xx = n - 1 - tx; int yy = m - 1 - ty;
        if(hasJump < 5 && seq[xx][yy] != '#' && dp[xx][yy][hasJump + 1] > dp[tx][ty][hasJump] + 1) {
            dp[xx][yy][hasJump + 1] = dp[tx][ty][hasJump] + 1;
            Q.push(make_tuple(xx, yy, hasJump + 1));
        }
    }
}

int main() {
    
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", seq[i]);
        }

        int sx = -1, sy = -1;
        int ex = -1, ey = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(seq[i][j] == 'S') {
                    sx = i; sy = j;
                }
                if(seq[i][j] == 'E') {
                    ex = i; ey = j;
                }
            }
        }

        bfs(sx, sy, ex, ey);

        int ans = INF;
        for(int i = 0; i <= 5; ++i) {
            ans = min(ans, dp[ex][ey][i]);
        }

        if(ans == INF) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}