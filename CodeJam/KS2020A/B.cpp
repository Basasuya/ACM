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


int dp[2][1505];
int vc[55][35];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n, K, P;
        scanf("%d %d %d", &n, &K, &P);
        // vector<vector<int>> vc(n, vector<int>());

        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= K; ++j) {
                int x; scanf("%d", &x);
                vc[i][j] = x;
            } 

            for(int j = 2; j <= K; ++j) {
                vc[i][j] += vc[i][j-1];
            }           
        }

        int fl = 0;
        memset(dp, -1, sizeof(dp));
        dp[fl][0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int l = 0; l <= P; ++l) {
                dp[fl ^ 1][l] = dp[fl][l];
                for(int j = 1; j <= K; ++j) {
                    if(l - j < 0) break;
                    if(dp[fl][l - j] != -1) dp[fl ^ 1][l] = max(dp[fl ^ 1][l], dp[fl][l - j] + vc[i][j]);
                }
            }
            fl ^= 1;
        }

        printf("Case #%d: ", cas);
        printf("%d\n", dp[fl][P]);
    }
    return 0;
}