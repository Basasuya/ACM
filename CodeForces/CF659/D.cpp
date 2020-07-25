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
// int dp[30][30][2];

int main() {
    // dp[0][0][1] = 0;
    // dp[0][0][0] = 0;
    // for(int i = 0; i < 5; ++i) {
    //     for(int j = 0; j < 5; ++j) {
    //         if(i == 0 && j == 0) continue;
    //         for(int k = 0; k < 2; ++k) {
    //             int mex[5]; memset(mex, 0, sizeof(mex));
    //             if(j) mex[dp[i][j - 1][k]] ++;
    //             if(i) mex[dp[i - 1][j][k ^ 1]] ++;
    //             int pos;
    //             for(int l = 0; l < 5; ++l) {
    //                 if(mex[l] == 0) {
    //                     pos = l;
    //                     break;
    //                 }
    //             }
    //             dp[i][j][k] = pos;
    //             debug(i, j, k, dp[i][j][k]);
    //         }
    //     }
    // }

    // for(int i = 0; i < 5; ++i) {
    //     for(int j = 0; j < 5; ++j) {
    //         debug(i, j, dp[i][j][0]);
    //     }
    // }

    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        vector<int> digit_count(30, 0);

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        for(int i = 0; i < n; ++i) {
            int tmp = A[i]; int count = 0;
            while(tmp) {
                if(tmp & 1) {
                    digit_count[count] ++;
                }
                count ++;
                tmp >>= 1;
            }
        }

        bool isDraw = true;
        int pos = -1;
        for(int i = 29; i >= 0; --i) {
            if(digit_count[i] % 2 == 1) {
                isDraw = false;
                pos = i;
                break;
            }
        }

        // debug(pos, digit_count[pos]);

        if(isDraw) printf("DRAW\n");
        else if(digit_count[pos] % 4 == 3 &&  (n - digit_count[pos]) % 2 == 0) printf("LOSE\n");
        else printf("WIN\n");
    }
    return 0;
}