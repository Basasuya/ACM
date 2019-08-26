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

int n, m;
int fr[MAXN], to[MAXN];
int fa[MAXN];
int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas=1; cas <= T; ++cas) {
        
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &fr[i], &to[i]);
        }
        int num = 0;
        for(int i = 0; i < m; ++i) {
            int t1 = Find(fr[i]);
            int t2 = Find(to[i]);
            if(t1 == t2) continue;
            fa[t1] = t2;
            if(++ num == n - 1) break;
        }

        if(num < n - 1) {
            debug(num);
            set<int> st;
            for(int i = 1; i <= n; ++i) {
                debug(Find(i));
                st.insert(Find(i));
            }
            num += (st.size() - 1) * 2;
        }

        printf("Case #%d: ", cas);
        printf("%d\n", num);
    }
    return 0;
}