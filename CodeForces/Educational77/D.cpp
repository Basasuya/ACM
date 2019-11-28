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

const int MAXN = 2e5 + 5;

int power[MAXN];
int L[MAXN], R[MAXN], D[MAXN], Index[MAXN];
int has[MAXN];
int n, m, k, t;

bool solve(int mid) {
    if(mid == 0) return true;

    int tag = power[mid - 1];
    for(int i = 0; i <= n + 1; ++i) has[i] = 0;
    for(int i = 0; i < k; ++i) {
        int id = Index[i];
        if(D[id] <= tag) break;
        has[L[id]] ++; has[R[id] + 1] --;
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        has[i] += has[i - 1];
        if(has[i]) cnt ++;
    }
    // debug(mid, cnt * 2 + n + 1);
    if(cnt * 2 + n + 1 <= t) return true;
    else return false;
}
int main() {
    
    while(~scanf("%d %d %d %d", &m, &n, &k, &t)) {
        for(int i = 0; i < m; ++i) scanf("%d", &power[i]);
        auto cmp = [](int a, int b) {return a > b;};
        auto cmp2 = [&](int a, int b) {return D[a] > D[b];};
        sort(power, power + m, cmp);
        for(int i = 0; i < k; ++i) {
            scanf("%d %d %d", &L[i], &R[i], &D[i]);
            Index[i] = i;
        }
        sort(Index, Index + k, cmp2);

        int l = 0; int r = m;
        
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(!solve(mid)) r = mid - 1;
            else l = mid + 1;
        }

        printf("%d\n", r);

    }
    return 0;
}