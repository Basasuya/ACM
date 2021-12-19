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

int getLen(int x) {
    int cnt = 0;
    while(x) {
        x /= 10;
        cnt ++;
    }
    return cnt;
}

ll getPow(int x) {
    ll ans = 1;
    for(int i = 0; i < x; ++i) {
        ans *= 10;
    }
    return ans;
} 
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int x1, p1;
        scanf("%d %d", &x1, &p1);
        int x2, p2;
        scanf("%d %d", &x2, &p2);

        int l1 = getLen(x1) + p1;
        int l2 = getLen(x2) + p2;
        
        if (l1 != l2) {
            printf("%c\n", l1 > l2 ? '>' : '<');
            continue;
        }

        ll ans1 = x1; ll ans2 = x2;

        if (p1 > p2) {
            ans1 *= getPow(p1 - p2);
        } else {
            ans2 *= getPow(p2 - p1);
        }

        if (ans1 == ans2) printf("=\n");
        else printf("%c\n", ans1 > ans2 ? '>' : '<');
    }
    return 0;
}