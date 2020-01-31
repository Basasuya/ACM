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

template<typename flow_t, typename cost_t>
struct MCMF {
  static const int N = 200, M = 100000;
  const flow_t inf = 1e9;
  struct node {
    int from, to, nxt;
    flow_t cap, flow;
    cost_t cost;
    node() {}
    node(int from, int to, int nxt, flow_t cap, cost_t cost):
      from(from), to(to), nxt(nxt), cap(cap), flow(0), cost(cost) {}
  } E[M];
  cost_t dis[N];
  int G[N], pre[N], vis[N], n, m;
  void init(int n) {
    this->n = n;
    this->m = 0;
    std::fill(G, G + n, -1);
  }
  void link(int u, int v, flow_t f, cost_t c) {
    E[m] = node(u, v, G[u], f, +c); G[u] = m++;
    E[m] = node(v, u, G[v], 0, -c); G[v] = m++;
  }
  bool extand(int S, int T) {
    std::fill(vis, vis + n, 0);
    std::fill(dis, dis + n, inf);
    std::queue<int> queue;
    dis[S] = 0;
    queue.push(S);
    for (; !queue.empty(); queue.pop()) {
      int u = queue.front();
      vis[u] = false;
      for (int it = G[u]; ~it; it = E[it].nxt) {
        int v = E[it].to;
        if (E[it].cap > E[it].flow && dis[v] > dis[u] + E[it].cost) {
          dis[v] = dis[u] + E[it].cost;
          pre[v] = it;
          if (!vis[v]) queue.push(v);
          vis[v] = true;
        }
      }
    }
    return dis[T] < inf; // 改成dis[T] <= 0 求可行流
  }
  std::pair<flow_t, cost_t> run(int S, int T) {
    flow_t max_flow = 0;
    cost_t min_cost = 0;
    while (extand(S, T)) {
      flow_t delta = inf;
      for (int u = T; u != S; u = E[pre[u]].from) {
        delta = std::min(delta, E[pre[u]].cap - E[pre[u]].flow);
      }
      min_cost += delta * dis[T];
      max_flow += delta;
      for (int u = T; u != S; u = E[pre[u]].from) {
        E[pre[u]].flow += delta;
        E[pre[u] ^ 1].flow -= delta;
      }
    }
    return {max_flow, min_cost};
  }
};


int p[105];
int has[105];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<int> num;
        vector<int> pos2;
        vector<int> pos;
        for(int i = 1; i <= n; ++i) has[i] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
            if(p[i] != 0) has[p[i]] ++;
            else pos.push_back(i);
        }
        for(int i = 1; i <= n; ++i) {
            if(has[i] == 0) num.push_back(i);
        }
       

        int s = 0; int t = 2 * n + 1;
        MCMF<int, int> solve;
        solve.init(t + 5);
        for(int i = 1; i <= n; ++i) {
            solve.link(i, 2*i, 1, 0);
        }

        if(p[1] == 0) {
            for(int i = 1; i <= n; ++i) {
                if(p[i] == 0) {
                    solve.link(s, i, 1, 0);
                }
            }
        } else solve.link(s, 1, 1, 0);

        if(p[n] == 0) {
            for(int i = 1; i <= n; ++i) {
                if(p[i] == 0) {
                    solve.link(i * 2, t, 1, 0);
                }
            }
        } else solve.link(n * 2, t, 1, 0);

        for(int i = 2; i <= n; ++i) {
            if(p[i] != 0 && p[i-1] != 0) {
                int t1 = p[i] % 2; int t2 = p[i-1] % 2;
                solve.link( (i - 1) * 2, i, 1, t1 != t2);
            }
        }

        for(int i = 0, len = zero.size(); i < len; ++i) {
            for(int j)
        }

        solve.init();

    }
    return 0;
}