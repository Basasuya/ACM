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

const int MAXN = 4e5 + 5;
int p[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &p[i]);

        int step = 0; int pre = -1;
        int g = 0, s = 0, b = 0;
        for(; step < n; ++ step) {
            if(step != 0 && pre != p[step]) {
                g = step;
                pre = p[step];
                step ++;
                break;
            } 
            pre = p[step];
        }

        for(; step < n; ++ step) {
            if(pre != p[step] && step > 2 * g) {
                s = step - g;
                pre = p[step];
                step ++;
                break;
            } 
            pre = p[step];
        }

        for(; step < n; ++ step) {
            if(pre != p[step] && step - s > g) {
                b = step - s;
                break;
            } 
            pre = p[step];
        }

        for(; step < n; ++ step) {
            if(step > n / 2) break;
            if(pre != p[step] && step <= n / 2) {
                b = step - s - g;
            }
            pre = p[step];
        }
        // debug(g, s, b);

        if(g + s + b <= n / 2 && g > 0 && s > 0 && b > 0 && g < b && g < s) printf("%d %d %d\n", g, s, b);
        else printf("0 0 0\n");

    }
    return 0;
}

/*

5
12
5 4 4 3 2 2 1 1 1 1 1 1
4
4 3 2 1
1
1000000
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
32
64 64 63 58 58 58 58 58 37 37 37 37 34 34 28 28 28 28 28 28 24 24 19 17 17 17 17 16 16 16 16 11
10
10 9 9 7 7 5 4 3 2 1

*/