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

const int MAXN = 3e3 + 5;
int A[MAXN];
int has[MAXN];
int cnt[MAXN];
int range[MAXN][MAXN];
// int pre[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    memset(range, 0, sizeof(range));

    while(T --) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        for(int i = 0; i < n; ++i) {
            ll tmp = 0;
            for(int j = 0; j <= n; ++j) {
                has[j] = 0;
            }
            
            for(int j = i; j < n; ++j) {
                tmp += has[A[j]];
                has[A[j]] ++;
                range[i][j] = tmp;
            }
        }

        // for(int i = 0; i < n; ++i) {
        //     for(int j = i; j < n; ++j) {
        //         debug(i, j, range[i][j]);
        //     }
        // }

        
        for(int i = 0; i <= n; ++i) {
            cnt[i] = 0;
        }
        for(int i = 0; i < n; ++i) {
            cnt[A[i]] ++;
        }

        ll ans = 0;
        
        for(int i = 0; i < n; ++i) {
            cnt[A[i]] --;
            for(int j = i + 1; j < n; ++j) {
                if(A[i] == A[j]) {
                    ans += range[i + 1][n - 1] - cnt[A[i]] + 1 - range[i + 1][j - 1] - range[j + 1][n - 1];
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}