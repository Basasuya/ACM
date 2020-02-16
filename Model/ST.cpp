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
#include <set>
#include <stack>
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
// string to_string(string s) { return '"' + s + '"'; }
// string to_string(const char* s) { return to_string((string) s); }
// string to_string(bool b) { return (b ? "true" : "false"); }
// template <typename A, typename B>
// string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
// template <typename A>
// string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
// void debug_out() { cerr << endl; }
// template <typename Head, typename... Tail>
// void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
// #ifdef LOCAL
// #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define debug(...) 42
// #endif


int n, q;


const int N = 5e4 + 5;
const int DEG = 16;
int st[N][DEG];
int lg[N];
int st2[N][DEG];


void build() {
    lg[1] = 0;
    for(int i = 2; i < N; i++){
        lg[i] = lg[i - 1];
        if((1 << (lg[i] + 1)) == i)
            lg[i]++;
    }
    for(int k = 1; k < DEG; ++k) {
        for(int i = 1; i <= n; ++i) {
            if(i + (1<<k) - 1 > n) break;
            st[i][k] = max(st[i][k - 1], st[i + (1<<(k-1))][k - 1]);
            st2[i][k] = min(st2[i][k - 1], st2[i + (1<<(k-1))][k - 1]);
        }
    }
}

int query(int x, int y) {
    int l = lg[y - x + 1];
    int t1 = max(st[x][l], st[y - (1<<l) + 1][l]);
    int t2 = min(st2[x][l], st2[y - (1<<l) + 1][l]);
    return t1 - t2;
}

int main() {
    // cout << ceil(log2(N)) << endl;
    
    while(~scanf("%d %d", &n, &q)) {
        for(int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            st[i][0] = x;
            st2[i][0] = x;
        }

        build();

        while(q --) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", query(x, y));
        }

    }
    return 0;
}