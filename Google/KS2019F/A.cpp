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

const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int A[MAXN];
int dp[MAXN][MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n, k;
        scanf("%d %d", &n, &k);
        k ++;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }
        memset(dp, INF, sizeof(dp));

        dp[1][1] = 0;
        for(int i = 2; i <= n; ++i) {
            int maxx = -1; int maxpos = -1;
            map<int, int> mp;

            for(int j = i; j > 0; --j) {
                mp[A[j]] ++;
                if(mp[A[j]] > maxx) {
                    maxx = mp[A[j]];
                    maxpos = A[j];
                } 

                for(int l = 1; l <= k; ++l) {
                    dp[i][l] = min(dp[i][l], dp[j-1][l - 1] + (i - j + 1 - maxx) );
                }
            }
            // debug(i);
            // debug(maxx);

            

            dp[i][1] = min(dp[i][1], i - maxx);
            // for(int l = 0; l <= k; ++l) debug(dp[i][l]); printf("\n");
        }

        int ans = INF;
        // for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= k; ++j) {
                ans = min(ans, dp[n][j]);
            }
        // }

        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
    return 0;
}

/*


4
8 2
300 100 300 300 200 100 800 500
5 3
100 100 100 100 3
7 3
10 20 40 10 10 30 30
10 2
30 30 60 60 90 90 60 60 30 30

*/