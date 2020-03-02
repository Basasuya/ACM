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

const int N = 2e5 + 5;
vector<int> G[N];

struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int dis[N], vis[N];
int path[N];

void bfs(int s) {
  queue<int> Q;
  memset(dis, INF, sizeof(dis));
  dis[s] = 0; vis[s] = 1;
  memset(vis, 0, sizeof(vis));
  Q.push(s);

  while(!Q.empty()) {
    int x = Q.front(); Q.pop();
    // if(vis[x]) continue;
    for(int i = head[x]; ~i; i = E[i].nx) {
      int to = E[i].to;

      if(!vis[to]) {
        vis[to] = 1;
        dis[to] = dis[x] + 1;
        Q.push(to);
      }
    }
  }
}


int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(head, -1, sizeof(head));
        tot = 0;
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 0; i < m; ++i) {
            int fr, to; scanf("%d %d", &fr, &to);
            add(to, fr);
            G[fr].push_back(to);
        }

        int k;
        scanf("%d", &k);
        for(int i = 1; i <= k; ++i) {
            scanf("%d", &path[i]);
        }

        bfs(path[k]);

        // for(int i = 1; i <= n; ++i) printf("%d ", dis[i]); printf("\n");

        int maxx = 0; int minn = 0;
        for(int i = 1; i <= k - 2; ++i) {
            bool nextIsin = false;
            int x = path[i];
            int cnt = 0;
            for(int j = 0, len = G[x].size(); j < len; ++j) {
                int to = G[x][j];
                debug(to, dis[to]);
                if(dis[x] == dis[to] + 1) {
                    if(to == path[i + 1]) {
                        nextIsin = true;
                    }
                    cnt ++;
                }
            }
            debug(i, nextIsin, cnt);

            if(nextIsin == false) maxx ++;
            else if(cnt > 1) maxx ++;
            // else if(dis[x] != k - i) maxx ++;


            if(dis[x] == dis[path[i + 1]] + 1);
            else minn ++;
        }


        printf("%d %d\n", minn, maxx);
    }
    return 0;
}

/*


6 9
1 5
5 4
1 2
2 3
3 4
4 1
2 6
6 4
4 2
4
1 2 3 4


*/