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

const int MAXN = 5e5 + 5;
const int MOD = 998244353;
int A[MAXN];
ll dp[MAXN];
int cnt[MAXN];
ll two[MAXN];

// ll Pow(ll x, ll y) {
//     ll ans = 1;
//     while(y) {
//         if(y & 1) ans = 1ll * ans * x % MOD;
//         x = 1ll * x * x % MOD;
//         y >>= 1;
//     }
//     return ans;
// }

// ll C(int x, int y) {
//     if(y == 0) return 1;
//     return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
// }

int main() {
    two[0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        two[i] = two[i - 1] * 2 % MOD;
    }

    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i <= n; ++i) {
            dp[i] = 0;
            cnt[i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            cnt[A[i]] ++;
        }

        

        ll ans = (two[cnt[1]] - 1 + MOD) % MOD;

        // int zero = 0; int one = 0; int two = 0;
        // for(int i = 0; i < n; ++i) {
        //     if(A[i] == 0) {
        //         zero ++;
        //     } else if (A[i] == 1) {
        //         one ++;
        //     } else if (A[i] == 2) {
        //         two ++;
        //     }
        // }

        // ans = (Pow(2, zero) - 1 + MOD) % MOD;

        // ans = (ans + Pow(2, one) - 1 + MOD) % MOD;

        // ans = (ans + ((Pow(2, zero) - 1 + MOD) % MOD) * ((Pow(2, two) - 1 + MOD) % MOD) % MOD)% MOD;


        for(int i = 0; i < n; ++i) {
            int val = A[i];
            
            cnt[val] --;
            
            ll add = 0;
            if (val == 0) {
                add = dp[0] + 1;
                dp[0] = (dp[0] + add) % MOD;
            } else {
                add = dp[val] + dp[val - 1];
                dp[val] = (dp[val] + add) % MOD;
            }

            if (val >= 2) {
                ans = (ans + dp[val - 2] * two[cnt[val]] % MOD * (two[cnt[val - 2]] + MOD) % MOD) % MOD;
            }


            
            // debug(ans);
        }

        for(int i = 0; i <= n; ++i) {
            // debug(dp[i]);
            ans = (ans + dp[i]) % MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}