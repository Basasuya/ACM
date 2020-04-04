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

int A[10];
int dp[2][200][15];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int sum = 0;
        for(int i = 1; i <= 9; ++i) {
            scanf("%d", &A[i]);
            if(A[i] > 20) A[i] = 20 + A[i] % 2;
            sum += A[i];
        }

        int odd = (sum + 1) / 2;
        int even = sum / 2;
        
        int fl = 0;
        int preSum = 0;
        for(int i = 0; i <= odd; ++i) {
            for(int j = 0; j < 11; ++j) {
                dp[0][i][j] = 0; dp[1][i][j] = 0;
            }
        }
        dp[fl][0][0] = 1;
        for(int l = 1; l <= 9; ++l) {
            for(int i = 0; i <= preSum; ++i) {
                int j = preSum - i;
                // for(int j = 0; j <= even; ++j) {
                    for(int k = 0; k <= A[l]; ++k) {
                        if(i + k <= odd & j + A[l] - k <= even) {
                            int tt = (11 + k * l % 11 - (A[l] - k) * l % 11) % 11;
                            for(int o = 0; o < 11; ++o) {
                                dp[fl ^ 1][i + k][ (o + tt) % 11] += dp[fl][i][o];
                            }
                        }
                    }
                // }
            }   
            
            preSum += A[l];

            for(int i = 0; i <= preSum; ++i) {
                // for(int j = 0; j <= even; ++j) {
                    for(int o = 0; o < 11; ++o) {
                        dp[fl][i][o] = 0;
                    }
                // }
            }
            fl ^= 1;
                     
        }

        printf("Case #%d: ", cas);

        printf("%s\n", dp[fl][odd][0] > 0 ? "YES" : "NO");

    }
    return 0;
}