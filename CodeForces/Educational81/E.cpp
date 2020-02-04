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

const int MAXN = 2e5 + 5;
int P[MAXN], A[MAXN], id[MAXN];

const ll lazyDefault = 0;
ll minn[MAXN << 2];
ll lazy[MAXN << 2];
void pushUp(int rt) {
    minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
}

void pushDown(int rt, int l, int r) {
    if(lazy[rt] != lazyDefault) {

        minn[rt << 1] += lazy[rt];
        minn[rt << 1 | 1] += lazy[rt];
        
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = lazyDefault;
    }
}

void Build(vector<ll> & vc, int l, int r, int rt) {
    lazy[rt] = lazyDefault;
    if(l == r) {
        minn[rt] = vc[l];
        return;
    }
    int m = (l + r) >> 1;
    Build(vc, lson);
    Build(vc, rson);
    pushUp(rt);
}

void Update(int L, int R, ll c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        minn[rt] += c;
        lazy[rt] += c;
        return;
    }
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m) Update(L, R, c, lson);
    if(R > m) Update(L, R, c, rson);
    pushUp(rt);
}

void debugTree(int l, int r, int rt) {
    printf("%d %d %lld\n", l, r, minn[rt]);
    if(l == r) return;
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    debugTree(lson);
    debugTree(rson);
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &P[i]);
            id[P[i]] = i;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }
        

        vector<ll> vc;
        ll sum = 0;     
        vc.push_back(sum);
        for(int i = 1; i <= n; ++i) {
            sum += A[id[i]];
            vc.push_back(sum);
        }

        Build(vc, 0, n, 1);

        // debugTree(0, n, 1);

        ll ans = 1e18;
        for(int i = 1; i < n; ++i) {
            Update(0, P[i] - 1, A[i], 0, n, 1);
            Update(P[i], n,  -A[i], 0, n, 1);
            
            // debug("yingyingying");
            // debugTree(0, n, 1);
            
            ans = min(ans, minn[1]);

        }
        printf("%lld\n", ans);
    }
    return 0;
}