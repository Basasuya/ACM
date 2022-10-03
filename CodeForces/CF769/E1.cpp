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

const int N = 3e5 + 5;

struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

int dep[N];
void dfs(int x, int pre, int h) {
    dep[x] = h;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int y = E[i].to;
        if(y == pre) continue;
        dfs(y, x, h + 1);
    }
}

void dfs2(int x, int pre, int h, int limit, int& max_dis, int& max_pos) {
    if (h > max_dis && dep[x] > limit) {
        max_dis = h;
        max_pos = x;
    }

    for(int i = head[x]; ~i; i = E[i].nx) {
        int y = E[i].to;
        if(y == pre) continue;
        dfs2(y, x, h + 1, limit, max_dis, max_pos);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        
        tot = 0;
        for(int i = 0; i <= n; ++i) {
            head[i] = -1;
        }

        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }

        dfs(1, 1, 0);
        
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            int l = 1; int r = n;
            while(l <= r) {
                int mid = (l + r) >> 1;

                int max_dis = -1; int max_pos = -1;
                for(int j = 1; j <= n; ++j) {
                    if (dep[j] <= mid) {
                        continue;
                    }
                    dfs2(j, j, 0, mid, max_dis, max_pos);
                    break;
                }

                // debug(max_dis, max_pos);

                if (max_pos == -1) {
                    r = mid - 1;
                } else {
                    int tmp = max_pos; max_pos = -1; max_dis = -1;
                    dfs2(tmp, tmp, 0, mid, max_dis, max_pos);

                    if ( (max_dis + 1) / 2 + i <= mid) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            ans.push_back(l);
        }


        for(int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
     
    }
    return 0;
}