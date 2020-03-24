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

int A[MAXN];
int S[MAXN][10];
int ord[MAXN];

bool cmp(int x, int y) {
    return A[x] > A[y];
}

ll dp[2][200];

int main() {
    int n, p, k;
    while(~scanf("%d %d %d", &n, &p, &k)) {

        for(int i = 0; i < n; ++i) ord[i] = i;
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < p; ++j)
                scanf("%d", &S[i][j]);
        }

        sort(ord, ord + n, cmp);
        int fl = 1;
        for(int i = 0; i < (1<<p); ++i) {
            dp[0][i] = dp[1][i] = -INF;
        }

        dp[fl ^ 1][0] = 0;

        for(int i = 1; i <= n; ++i) {
            int target = ord[i-1];
            for(int j = 0; j < (1<<p); ++j) {
                int bit_count = 0;
                for(int k = 0; k < p; ++k) {
                    if( (j >> k) & 1 )
                        bit_count ++;
                }
                if(bit_count > i) continue;

                for(int k = 0; k < p; ++k) {
                    if( (j >> k) & 1 ) {
                        int pre = j ^ (1<<k);
                        dp[fl][j] = max(dp[fl][j], dp[fl ^ 1][pre] + S[target][k]);
                    }
                }
                
                if(i - bit_count <= k) dp[fl][j] = max(dp[fl][j], dp[fl ^ 1][j] + A[target]);
                else dp[fl][j] = max(dp[fl][j], dp[fl ^ 1][j]);
            }

            // for(int j = 0; j < (1<<p); ++j) printf("%d ", dp[fl][j]); printf("\n");
            
            fl ^= 1;
            for(int j = 0; j < (1<<p); ++j) {
                dp[fl][j] = -INF;
            }

        }

        printf("%lld\n", dp[fl ^ 1][(1<<p) - 1]);
    }
    return 0;
}