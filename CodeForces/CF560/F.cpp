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

const int MAXN = 2e5 + 5;
int n, m;
int k[MAXN];
int has[MAXN];
int id[MAXN];
struct Node{
    int t, d;
    // bool operator <(const Node &T) const {
    //     return d < T.d;
    // }
}E[MAXN];
int sum;
bool cmp(Node &a, Node &b) {
    return a.d < b.d;
}
bool cmp2(int a, int b) {
    return has[a] < has[b];
}
bool solve(int x) {
    // int edge = lower_bound(E, E + m, x) - E;
    memset(has, -1, sizeof(has));
    for(int i = 0; i < m; ++i) {
        if(E[i].d > x) break; 
        has[E[i].t] = E[i].d; 
    }
    for(int i = 1; i <= n; ++i) {
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp2);
    int tmp = 0;
    for(int i = 1; i <= n; ++i) {
        if(has[id[i]] == -1 || k[id[i]] == 0) continue;
        int hhh = has[id[i]] - tmp;
        if(hhh >= k[id[i]]) {
            tmp += k[id[i]];
        } else tmp += hhh;
    }
    return (sum - tmp) * 2 + tmp <= x;
}
int main() {
    
    while(~scanf("%d %d", &n, &m)) {
        sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &k[i]);
            sum += k[i];
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &E[i].d, &E[i].t);
        }
        sort(E, E + m, cmp);

        int l = 1; int r = sum * 2;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(solve(mid)) r = mid - 1;
            else l = mid + 1;
        } 
        printf("%d\n", l);
    }
    return 0;
}