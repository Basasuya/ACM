#include <iostream>
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

const int MAXN = 1e5 + 5;
int X[MAXN], Y[MAXN];
int fa[MAXN];
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &X[i], &Y[i]);
        }

        for(int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        for(int i = 0; i < k; ++i) {
            int t1 = find(X[i]); int t2 = find(Y[i]);
            if(t1 != t2) {
                fa[t1] = t2;
            }
        }

        map<int, int> mp;
        for(int i = 1; i <= n; ++i) {
            int t1 = find(i);
            mp[t1] ++;
        }
        int cnt = 0;
        for(auto it : mp) {
            if(it.second > 1) {
                cnt += it.second - 1;
            }
        }

        printf("%d\n", k - cnt);
        

    }
    return 0;
}