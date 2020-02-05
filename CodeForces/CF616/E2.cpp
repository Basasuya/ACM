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

const int MAXN = 3e5 + 5;
vector<vector<int> > subset;
char state[MAXN];
int link[MAXN][2];
int side[MAXN];
int cnt[MAXN][2];
int fa[MAXN];
int siz[MAXN];
int ans;

int Find(int x) {
    return (fa[x] == x) ? fa[x] : (fa[x] = Find(fa[x]));
}

void add(int cc, int s0, int s1)
{
    cc = Find(cc);
    ans -= min(cnt[cc][0], cnt[cc][1]);
    cnt[cc][0] = min(INF, cnt[cc][0] + s0);
    cnt[cc][1] = min(INF, cnt[cc][1] + s1);
    ans += min(cnt[cc][0], cnt[cc][1]);
}

void merge(int x, int y) {
    int t1 = Find(x); int t2 = Find(y);
    if(t1 == t2) return;
    if(siz[t1] < siz[t2]) swap(t1, t2);
    
    add(t1, cnt[t2][0], cnt[t2][1]);
    add(t2, -cnt[t2][0], -cnt[t2][1]);
    siz[t1] += siz[t2];
    fa[t2] = t1;
}

void dfs(int x) {
    cnt[x][side[x]] = 1;
    for(auto item : subset[x]) {
        if(link[item][1] == -1) continue;
        int nex = link[item][0] + link[item][1] - x;
        if(side[nex] == -1) {
            side[nex] = side[x] ^ (state[item] == '0');
            dfs(nex);
        }
    }
}


int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        ans = 0;
        scanf("%s", state);
        subset.clear();
        for(int i = 0; i < max(n, k); ++i) {
            siz[i] = 1;
            fa[i] = i;
            link[i][0] = link[i][1] = -1;
            side[i] = -1;
            cnt[i][0] = cnt[i][1] = 0;
        }
        for(int i = 0; i < k; ++i) {
            vector<int> tmp;
            int c; scanf("%d", &c);
            for(int j = 0; j < c; ++j) {
                int x; scanf("%d", &x); --x;
                tmp.push_back(x);
                if(link[x][0] == -1) link[x][0] = i;
                else link[x][1] = i;
            }
            subset.push_back(tmp);
        }

        for(int i = 0; i < k; ++i) {
            if(side[i] == -1) {
                side[i] = 0;
                dfs(i);
            }
        }

        for(int i = 0; i < n; ++i) {
            int t0 = link[i][0]; int t1 = link[i][1];
            if(t0 != -1 && t1 != -1) {
                merge(t0, t1);
            } else if(t0 != -1) {
                int choose = side[t0] ^ (state[i] == '0');
                if(choose == 1) add(t0, 0, INF);
                else add(t0, INF, 0);
            }
            printf("%d\n", ans);
        }
        
    }
    return 0;
}