#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forw(i, l, r) for (int i = l; i < r; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
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

const int INF = 0x3f3f3f3f;
const int MAXN = 105;
const int MAXM = 1e6 + 5;
int mp[MAXN][MAXN];
int p[MAXM];
pair<int, int> dp[MAXM];
int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%1d", &mp[i][j]);
                if(mp[i][j] == 0) mp[i][j] = INF;
            }
        }

        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(i  == j) continue;
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &p[i]);
        }
        int maxDis = -1;
        forw(i, 1, n + 1) {
            forw(j, 1, n + 1) {
                if(mp[i][j] != INF) maxDis = max(maxDis, mp[i][j]);
                debug(i, j, mp[i][j]);
            }
        }

        dp[1] = make_pair(-1, 0);
        for(int i = 2; i <= m; ++i) {
            int to = p[i]; int minn = INF; int pos = -1;
            for(int j = max(1, i - maxDis); j < i; ++j) {
                int t2 = dp[j].second;
                if(mp[p[j]][to] == i - j) {
                    if(minn > t2) {
                        minn = t2;
                        pos = j;
                    }
                }
            }
            assert(pos != -1);
            dp[i] = make_pair(pos, minn + 1);
        }

        vector<int> ans;
        
        int tmp = m;
        while(1) {
            ans.push_back(p[tmp]);
            tmp = dp[tmp].first;
            if(tmp == -1) break;
        }

        reverse(ans.begin(), ans.end());

        printf("%d\n", (int)ans.size());
        for(int i = 0, len = ans.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        } printf("\n");

    }
    return 0;
}