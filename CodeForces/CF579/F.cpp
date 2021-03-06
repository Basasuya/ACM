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

const int MAXN = 30005;
int a[MAXN], b[MAXN], id[MAXN];
int cmp(int x, int y) {
    if(b[x] * b[y] < 0) return b[x] >= 0;
    else if(b[x] * b[y] == 0) {
        if(b[x] < 0) return 0;
        if(b[y] < 0) return 1;
        return a[x] < a[y];
    }
    else if(b[x] < 0) return a[x] + b[x] > a[y] + b[y];
    else return a[x] < a[y];
}
int main() {
    int n, r;
    while(~scanf("%d %d", &n, &r)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &a[i], &b[i]);
            id[i] = i;
        }
        sort(id, id + n, cmp);
        bool flag= true;
        for(int i = 0, tmp = r; i < n && flag; ++i) {
            
            int t1 = a[id[i]];
            int t2 = b[id[i]];
            // debug(id[i], t1, t2, tmp);
            flag &= t1 <= tmp;
            tmp += t2;
            flag &= tmp >= 0;
        }
        // debug(flag);
        printf("%s\n", flag == true? "YES" : "NO");
    }
    return 0;
}