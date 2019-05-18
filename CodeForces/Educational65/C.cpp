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
// #define ll long long
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

const int N = 5e5 + 5;
int fa[N];
int cnt[N];
int Find(int x) { return fa[x] == x ? x : (fa[x] = Find(fa[x])); }
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            fa[i] = i;
            cnt[i] = 0;
        }
        for(int i = 0; i < m; ++i) {
            int k; scanf("%d", &k);
            int pre = -1; int now;
            for(int j = 0; j < k; ++j) {
                scanf("%d", &now);
                if(pre != -1) {
                    int t1 = Find(pre); int t2 = Find(now);
                    if(t1 != t2) {
                        fa[t1] = t2;
                    } 
                }
                pre = now;
            }
        }

        for(int i = 1; i <= n; ++i) {
            int t1 = Find(i);
            cnt[t1] ++;
        }

        for(int i = 1; i <= n; ++i) {
            int t1 = Find(i);
            if(i != 1) printf(" ");
            printf("%d", cnt[t1]); 
        }
        printf("\n");
    }
    return 0;
}