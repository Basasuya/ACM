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

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int A[MAXN];
int cnt[MAXN];
int dp[2][3];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            cnt[A[i]] ++;
        }
        sort(A, A + n);
        // n = unique(A, A + n) - A;
        int fl = 0;
        for(int i = 0; i < n; ++i) {
            memset(dp[fl ^ 1], INF, sizeof(dp[fl ^ 1]));

            if(i == 0) {
                dp[fl ^ 1][0] = 1;
                dp[fl ^ 1][1] = 1;
                dp[fl ^ 1][2] = 1;
            } else {
                for(int j = -1; j < 2; ++j) {
                    for(int l = -1; l < 2; ++l) {
                        int t1 = j + A[i-1]; int t2 = l + A[i];
                        if(t1 < t2) dp[fl ^ 1][l + 1] = min(dp[fl ^ 1][l + 1], dp[fl][j + 1] + 1); 
                        else if(t1 == t2) dp[fl ^ 1][l + 1] = min(dp[fl ^ 1][l + 1], dp[fl][j + 1]); 
                    }
                }
            }
            fl ^= 1;
        }

        int ans1 = min(min(dp[fl][0], dp[fl][1]), dp[fl][2]);

        fl = 0;
        for(int i = 0; i < n; ++i) {
            memset(dp[fl ^ 1], 0, sizeof(dp[fl ^ 1]));

            if(i == 0) {
                dp[fl ^ 1][0] = 1;
                dp[fl ^ 1][1] = 1;
                dp[fl ^ 1][2] = 1;
            } else {
                for(int j = -1; j < 2; ++j) {
                    for(int l = -1; l < 2; ++l) {
                        int t1 = j + A[i-1]; int t2 = l + A[i];
                        if(t1 < t2) dp[fl ^ 1][l + 1] = max(dp[fl ^ 1][l + 1], dp[fl][j + 1] + 1); 
                        else if(t1 == t2) dp[fl ^ 1][l + 1] = max(dp[fl ^ 1][l + 1], dp[fl][j + 1]); 
                    }
                }
            }
            // debug(dp[fl ^ 1][0], dp[fl ^ 1][1], dp[fl ^ 1][2]);
            fl ^= 1;
        }

        int ans2 = max(max(dp[fl][0], dp[fl][1]), dp[fl][2]);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}