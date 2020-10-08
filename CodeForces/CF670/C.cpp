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

const int MAXN = 1e5 + 5;

int n;
struct Node{
    int to, nx;
}E[MAXN << 1];
int head[MAXN];
int son[MAXN];
int tot;
int max_componet_val;
int max_componet_cnt;
int max_componet_pos;
int another_max_componet_pos;
pair<int, int> one_leaf;

void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

void dfs(int x, int pre) {
    son[x] = 1; int max_son = -1;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        dfs(to, x);
        son[x] += son[to];
        max_son = max(max_son, son[to]);
    }
    int max_componet = max(max_son, n - son[x]);

    debug(x, max_componet, son[x]);
    if (max_componet < max_componet_val) {
        max_componet_val = max_componet;
        max_componet_cnt = 1;
        max_componet_pos = x;
    } else if(max_componet == max_componet_val) {
        max_componet_cnt ++;
        another_max_componet_pos = x;
    }
}

void FindOneLeaf(int x, int pre) {
    if(one_leaf != make_pair(-1, -1)) {
        return;
    }

    int cnt = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre || to == max_componet_pos) continue;
        cnt ++;
        FindOneLeaf(to, x);
    }

    if(cnt == 0) {
        one_leaf = {pre, x};
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);

        vector<pair<int, int> > E;

        for(int i = 0; i <= n; ++i) {
            head[i] = -1;
            son[i] = 0;
        }
        tot = 0;
        
        for(int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            add(x, y);
            add(y, x);
            E.push_back({x, y});
        }

        max_componet_val = n + 5;
        max_componet_cnt = 0;

        dfs(1, 1);

        debug(max_componet_cnt, another_max_componet_pos, max_componet_pos, max_componet_val);

        if(max_componet_cnt == 1) {
            printf("%d %d\n", E[0].first, E[0].second);
            printf("%d %d\n", E[0].first, E[0].second);
            continue;
        }

        assert(max_componet_val == n / 2);
        assert(n % 2 == 0);

        one_leaf = {-1, -1};
        FindOneLeaf(another_max_componet_pos, another_max_componet_pos);
         
        printf("%d %d\n", one_leaf.first, one_leaf.second);
        printf("%d %d\n", max_componet_pos, one_leaf.second);
    }
    return 0;
}

/*

15
4
1 2
2 3
3 4
4
1 2
2 4
3 4
4
1 2
1 3
1 4
4
1 3
2 3
4 3
4
1 4
3 4
2 3
4
4 1
3 2
2 1
5
1 2
2 3
3 4
4 5
5
1 2
2 3
4 1
5 1
5
1 2
3 1
4 1
1 5
6
1 2
2 3
3 4
4 5
5 6
6
1 3
2 3
3 4
4 5
4 6
3
1 2
1 3
3
2 1
2 3
3
3 1
3 2
4
1 2
2 3
2 4

*/