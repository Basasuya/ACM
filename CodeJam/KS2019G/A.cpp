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
const int MAXN = 1e5 + 5;
// int Page[MAXN];
// int Read[MAXN];
int torn[MAXN];
int tag[MAXN];
int has[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 0; i <= n; ++i) {
            tag[i] = 0; 
            torn[i] = 0;
            has[i] = 0;
        }

        for(int i = 0; i < m; ++i) {
            int x; scanf("%d", &x);
            torn[x] = 1;
        }
        for(int i = 0; i < q; ++i) {
            int x; scanf("%d", &x);
            tag[x] ++;
        }

        for(int i = 1; i <= n; ++i) {
            if(tag[i]) {
                for(int j = i; j <= n; j += i) {
                    has[j] += tag[i];
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(has[i] && !torn[i]) {
                // debug(i, has[i]);
                ans += has[i];
            }
        }
        printf("Case #%d: ", cas);
        printf("%lld\n", ans);
        
    }
    return 0;
}

/*


6
11 1 2
8
2 3
11 11 11
1 2 3 4 5 6 7 8 9 10 11
1 2 3 4 5 6 7 8 9 10 11
1000 6 1
4 8 15 16 23 42
1

*/