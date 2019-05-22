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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
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

const int MAXN = 305;
int C[MAXN], J[MAXN];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main() {   
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &C[i], &J[i]);
        }
        int t1 = -1, t2 = -1;
        bool ok = false;
        for(int i = 1; i <= 300 && !ok; ++i) {
            for(int j = 1; j <= 300 && !ok; ++j) {
                bool suc = true;
                for(int z = 1; z < n && suc; ++z) {
                    ll t1 = C[z] - C[z - 1]; ll t2 = J[z] - J[z - 1];
                    // printf("hhh: %d %d %d %d %d\n", t1 * i + t2 + j, i, j, t1, t2);
                    if(t1 * i + t2 * j <= 0) {
                        suc = false;
                        break;
                    }
                }
                if(suc) {
                    t1 = i; t2 = j;
                    ok = true;
                    break;
                }
            }
        }

        printf("Case #%d: ", cas);
        if(t1 == -1) printf("IMPOSSIBLE\n");
        else printf("%d %d\n", t1, t2);
    }
    return 0;
}

/*


3
3
1 1
1 2
2 1
4
1 2
2 4
2 1
4 2
3
1 2
1 3
2 3

*/