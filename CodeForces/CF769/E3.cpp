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

int dp[N];
int dfs(int x, int pre, int h) {
    int max_dis = h;  int second_max_dis = h;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int y = E[i].to;
        if(y == pre) continue;
        int tmp = dfs(y, x, h + 1);
        if(tmp > max_dis) {
            second_max_dis = max_dis;
            max_dis = tmp;
        } else if (tmp > second_max_dis) {
            second_max_dis = tmp;
        }
    }

    int limit = min(max_dis, second_max_dis) - 1;
    
    if(limit) {
        dp[limit] = max(dp[limit], max_dis + second_max_dis - 2 * h);
    }

    return max_dis;
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
            dp[i] = 0;
        }

        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }

        int max_ans = dfs(1, 1, 0);

        for(int i = n - 1; i >= 1; --i) {
            dp[i] = max(dp[i], dp[i + 1]);
        }
    
        vector<int> ans;
        int limit = 1;
        for(int i = 1; i <= n; ++i) {
            while(limit < max_ans) {
                if ( (dp[limit] + 1) / 2 + i <= limit) {
                    break;
                } else {
                    limit ++;
                }
            }
            ans.push_back(limit);
        }


        for(int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
     
    }
    return 0;
}