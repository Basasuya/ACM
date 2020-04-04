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
#define forw(i, l, r) for (int i = l; i < r; ++i)
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

const int MAXN = 1e5 + 5;
double C[MAXN], E[MAXN];
double A[MAXN], B[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas=1; cas <= T; ++cas) {
        
        int D, S;
        scanf("%d %d", &D, &S);
        assert(S <= 2);

        for(int i = 0; i < S; ++i) {
            scanf("%lf %lf", &C[i], &E[i]);
        }
        for(int i = 0; i < D; ++i) {
            scanf("%lf %lf", &A[i], &B[i]);
        }

        printf("Case #%d: ", cas);
        int split = 100;
        for(int i = 0; i < D; ++i) {
            bool flag = false;
            if(S == 1) {
                double f = A[i] / C[0];
                f = min(max(0.0, f), 1.0);
                double ans1 = f * C[0]; double ans2 = (1-f) * E[0];
                if(ans1 >= A[i] && ans2 >= B[i]) flag = true;
            } else {
                for(int k = 0; k <= split && !flag; ++k) {
                    for(int j = 0; j <= split && !flag; ++j) {
                        double c1 = k * 1.0 * C[0] / split;
                        double c2 = (split - k) * 1.0 * E[0] / split;
                        double t1 = j * 1.0 * C[1] / split;
                        double t2 = (split - j) * 1.0 * E[1] / split;
                        
                        if(c1 + t1 >= A[i] && c2 + t2 >= B[i]) flag = true;
                    }
                }
            }
            if(flag) printf("Y"); else printf("N");
        }
        printf("\n");
        
        
        
        
    }
    return 0;
}