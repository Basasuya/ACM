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
int tree[MAXN];
int has[MAXN];

int treesize;
int Sum(int x) {
    if(x > treesize) x = treesize;
    if(x <= 0) return 0;
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= x & -x;
    }
    return ans;
}

void Add(int x, int d) {
    while(x <= treesize) {
        tree[x] += d;
        x += x & -x;
    }
}


int main() {
    int q, x;
    while(~scanf("%d %d", &q, &x)) {
        for(int i = 0; i <= q; ++i) tree[i] = 0;
        for(int i = 1; i <= q; ++i) has[i] = 0;

        treesize = q;
        for(int i = 0; i < q; ++i) {
            int tt; scanf("%d", &tt);
            tt = (tt % x) + 1;
            // debug(tt);

            if(1ll * has[tt] * x + tt <= q) Add(1ll * has[tt] * x + tt, 1);
            
            int l = 0; int r = q;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(Sum(mid) != mid) r = mid - 1; 
                else l = mid + 1;
            }

            printf("%d\n", r);
            has[tt] ++;
        }
    }
    return 0;
}