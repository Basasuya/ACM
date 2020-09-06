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

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int a, b, x, y, n;
        scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);
        
        int need = a - x + b - y;
        
        if(need <= n) {
            printf("%lld\n", 1ll * x * y);
            continue;
        }

        if(x < y) {
            swap(a, b);
            swap(x, y);
        }

        int still_need = need - n;

        int need_2 = min(x - y, b - y);

        if(need_2 >= still_need) {
            printf("%lld\n", 1ll * x * (y + still_need));
            continue;
        }
        
        still_need -= need_2;
        y += need_2;


        if(y == b) {
            printf("%lld\n", 1ll * (x + still_need) * y);
            continue;
        }

        int need_3 = 2 * (min(a, b) - x);

        if(need_3 >= still_need) {
            printf("%lld\n", 1ll * (x + still_need / 2) * (y + (still_need + 1) / 2));
            continue;
        }

        still_need -= need_3;
        x += need_3 / 2;
        y += need_3 / 2;
        if(x == a) {
            printf("%lld\n", 1ll * x * (y + still_need));
        } else {
            printf("%lld\n", 1ll * y * (x + still_need));
        }
    }
    return 0;
}