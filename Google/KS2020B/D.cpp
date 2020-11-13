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

double solve(int W, int H, int L, int U, int R, int D) {
    vector<vector<double> > dp(W + 5, vector<double>(H + 5, 0.0));

    // debug(W, H, L, U, R, D);

    dp[0][0] = 1.0;
    for(int i = 0; i < W; ++i) {
        for(int j = 0; j < H; ++j) {
            // if(i >= L - 1 && i < R && j >= U - 1 && j < D) {
            //     // debug("hhhh");
            //     dp[i][j] = 0.0;
            //     continue;
            // }

            debug(i, j, dp[i][j]);
            
            int cnt = 0;
            if(i != W - 1) cnt ++;
            if(j != H - 1) cnt ++;

            if(i != W - 1) dp[i + 1][j] += dp[i][j] / cnt;
            if(j != H - 1) dp[i][j + 1] += dp[i][j] / cnt;
        }
    }
    return dp[W - 1][H - 1];
}


int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int W, H, L, U, R, D;
        scanf("%d %d %d %d %d %d", &W, &H, &L, &U, &R, &D);

        printf("Case #%d: %.7f\n", cas, solve(W, H, L, U, R, D));
    }
    return 0;
}

/*

4
3 3 2 2 2 2
5 5 2 2 2 2
5 3 1 2 4 2
1 10 1 3 1 5
6 4 1 3 3 4

*/