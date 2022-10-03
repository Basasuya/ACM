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

const int  N = 2e5 + 5;
const int  MAXN = 1e6 + 5;

struct Node{
    int fr, to, nx, dis;
}E[MAXN];
int head[N]; int tot = 0; 

int getBits(int x) {
    int cnt = 0;
    while(x) {
        if (x & 1) cnt ++;
        x >>= 1;
    }
    return cnt;
}

void add(int fr, int to, int dis) {
    E[tot].to = to; E[tot].nx = head[fr]; E[tot].dis = getBits(dis) % 2; head[fr] = tot ++;
}



int prefix[N];
int fa[N];
bool success;
int Find(int x) { return fa[x] == x ? fa[x] : (fa[x] = Find(fa[x])); }

void dfs(int x, int pre) {
    if(!success) return;

    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to; if (to == pre) continue;
        
        if(prefix[to] != -1) {
            if ( (prefix[to] ^ E[i].dis) != prefix[x]) {
                debug(to, x, prefix[x], E[i].dis);
                success = false; break;
            }
        } else {
            prefix[to] = E[i].dis ^ prefix[x];

            debug(to, prefix[to]);
            dfs(to, x);
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m;
        scanf("%d %d", &n, &m);

        // data init
        for(int i = 0; i <= n; ++i) {
            head[i] = -1;
            fa[i] = i;
            prefix[i] = -1;
        }
        tot = 0;

        vector<tuple<int, int, int> > ans;

        for(int i = 1; i < n; ++i) {
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            ans.push_back({x, y, v});

            
            
            if (v != -1) {
                int tx = Find(x); int ty = Find(y);
                if(tx != ty) {
                    fa[tx] = ty;
                }
                add(x, y, v);
                add(y, x, v);
            }
        }

        for(int i = 0; i < m; ++i) {
            int a, b, p;
            scanf("%d %d %d", &a, &b, &p);
            
            add(a ,b, p);
            add(b, a, p);

            int ta = Find(a); int tb = Find(b);
            if (ta != tb) {
                fa[ta] = tb;
            }
        }

        vector<vector<int> > group(n + 1, vector<int>());
        for(int i = 1; i <= n; ++i) {
            int ti = Find(i);
            group[ti].push_back(i);
        }

        success = true;
        for(int i = 1; i <= n && success; ++i) {
            if(group[i].size() > 0) {
                int node = group[i][0];
                prefix[node] = 0;
                debug(node, prefix[node]);
                dfs(node, node);
            }
        }

        // for(int i = 1; i <= n; ++i) { printf("%d ", prefix[i]); } printf("\n");

        if(!success) printf("No\n");
        else {
            for(int i = 0, len = ans.size(); i < len; ++i) {
                auto& tmp = ans[i];
                if (get<2>(tmp) == -1) {
                    get<2>(tmp) = prefix[get<0>(tmp)] ^ prefix[get<1>(tmp)];
                }
            }
            printf("YES\n");
            for(int i = 0, len = ans.size(); i < len; ++i) {
                auto& tmp = ans[i];
                printf("%d %d %d\n", get<0>(tmp), get<1>(tmp), get<2>(tmp));
            }
        }



    }
    return 0;
}