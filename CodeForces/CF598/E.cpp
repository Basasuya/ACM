#include <iostream>
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
#define mp make_pair
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
const int MAXN = 2e5 + 5;
struct Node{
    int id; int val;
}per[MAXN];
bool cmp(Node &A, Node &B) {
    return A.val < B.val;
}
int dp[MAXN][5];
int len[MAXN];
int ans[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, INF, sizeof(dp));
        memset(len, -1, sizeof(len));

        for(int i = 0; i < n; ++i) {
            scanf("%d", &per[i].val);
            per[i].id = i;
        }

        sort(per, per + n, cmp);
        
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                dp[0][1] = 0; 
                continue;
            }

            dp[i][1] = min(dp[i][1], dp[i-1][3]);
            dp[i][2] = min(dp[i][2], dp[i-1][1] + per[i].val - per[i-1].val);
            dp[i][3] = min(dp[i][3], dp[i-1][2] + per[i].val - per[i-1].val); len[i] = 3;
            if(dp[i][3] > dp[i-1][3] + per[i].val - per[i-1].val) {
                dp[i][3] = dp[i-1][3] + per[i].val - per[i-1].val;
                len[i] = len[i-1] + 1;
            }

            // debug(i);
            // for(int j = 1; j < 4; ++j) {
            //     printf("%d ", dp[i][j]);
            // } printf("\n");

        }

        int tag = n-1; int cnt = n - 1; int team = 1;
        while(1) {
            for(int i = 0; i < len[tag]; ++i) {
                ans[per[cnt --].id] = team;
            }
            tag -= len[tag];
            if(tag < 0) break;
            team ++;
            
        }

        printf("%d %d\n", dp[n-1][3], team);
        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        } printf("\n");

        
    }
    return 0;
}