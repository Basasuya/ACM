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

const int MOD = 998244353;

ll dp[505][2];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<int> order;

        for(int i = 0; i < n; ++i) {
            char tmp[5];
            scanf("%s", tmp);
            if(tmp[0] == '+') {
                int x; scanf("%d", &x);
                order.push_back(x);
            } else {
                order.push_back(0);
            }
        }

        ll ans = 0;
        
        for(int i = 0; i < n; ++i) {

            if (order[i] > 0) { // only iterate + x
                for(int j = 0; j <= n; ++j) { dp[j][0] = dp[j][1] = 0; }
                int flag = 0;
                dp[0][flag] = 1;
                int target = order[i];

                for(int j = 0; j < n; ++j) {
                    // if(j > i) {
                    //     for(int k = 0; k <= n; ++k) {
                    //         ans = (ans + dp[k][flag] * order[i]) % MOD;
                    //     }
                    // }

                    // printf("turn %d: ", j); for(int k = 0; k <= n; ++k) printf("%lld ", dp[k][flag]); printf("\n");

                    for(int k = 0; k <= n; ++k) dp[k][flag ^ 1] = dp[k][flag];
                    flag ^= 1;
                        
                    if (j == i) {
                        continue; // skip itself
                    }

                    // if (j == 0) {
                    //     if (order[j] <= target && order[j] > 0) dp[1][flag] = 1;
                    //     continue;
                    // }

                    for(int k = 0; k <= n; ++k) {
                        if (order[j] == 0) {
                            if(k < n) dp[k][flag] = (dp[k + 1][flag ^ 1] + dp[k][flag]) % MOD;
                        } else if ( (order[j] == target && j > i) || order[j] > target ) {
                            dp[k][flag] = (dp[k][flag] * 2) % MOD;
                        } else {
                            if(k) dp[k][flag] = (dp[k - 1][flag ^ 1] + dp[k][flag]) % MOD;
                            // if (k == 1) dp[1][flag] = (dp[1][flag] + dp[0][flag]) % MOD;
                            // else dp[k][flag] = (1 + dp[k][flag]) % MOD;
                        }
                    }
                    if (order[j] == 0 && j < i) dp[0][flag] = (dp[0][flag] + dp[0][flag ^ 1]) % MOD;
                }
                
                // printf("final turn: "); for(int k = 0; k <= n; ++k) printf("%lld ", dp[k][flag]); printf("\n");

                for(int k = 0; k <= n; ++k) {
                    ans = (ans + dp[k][flag] * order[i]) % MOD;
                }
            }
        }


        printf("%lld\n", ans);
    }
    return 0;
}