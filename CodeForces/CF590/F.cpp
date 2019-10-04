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

const int MAXN = 1e6 + 5;
const int MAXM = 1048576;
char seq[MAXN];
int cnt[MAXM];
int dp[MAXM];
int main() {
    while(~scanf("%s", seq)) {
        int len = strlen(seq);
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0; i < len; ++i) {
            int chaCnt[20];
            memset(chaCnt, 0, sizeof(chaCnt));
            int tmp = 0;
            for(int j = 0; j < 20 && (i + j) < len; ++j) {
                chaCnt[seq[i + j] - 'a'] ++;
                if(chaCnt[seq[i + j] - 'a'] > 1) {
                    break;
                }
                tmp += 1<<(seq[i + j] - 'a');
                cnt[tmp] ++;
            }
        }

        for(int i = 0; i < MAXM; ++i) {
            int bc = bitCount(i);
            if(cnt[i]) dp[i] = max(dp[i], bc);
            for(int j = 0; j < 20; ++j) {
                if( ((i >> j) & 1) == 0) {
                    int tmp = i + (1<<j);
                    if(tmp < MAXM) {
                        dp[tmp] = max(dp[tmp], dp[i]);
                    }
                }
            }
        }

        // for(int i = 0; i < 8; ++i) debug(dp[i], cnt[i]);

        int ans = -1;
        for(int i = 0; i < MAXM; ++i) {
            if(cnt[i]) {
                int bc = bitCount(i);
                ans = max(ans, bc);
                int tt = (1<<20) - 1 - i;
                if(dp[tt] > 0) {
                    ans = max(ans, dp[tt] + bc);
                }
                // if(i < 8) debug(dp[tt], i, bc);
            } 
        }

        printf("%d\n", ans);
    }
    return 0;
}