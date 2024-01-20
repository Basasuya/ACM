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

int A[MAXN];
int tree[MAXN << 2];
int lazy[MAXN << 2];

void build(int l, int r, int rt) {
    tree[rt] = INF;
    lazy[rt] = 0;
    if(l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void pushUp(int rt) {
    tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}

void pushDown(int rt, int l, int r) {
    if(lazy[rt] != 0) {
        int m = (l + r) >> 1;

        if(tree[rt << 1] != INF) tree[rt << 1] += lazy[rt];
        if(tree[rt << 1 | 1] != INF) tree[rt << 1 | 1] += lazy[rt];
        
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}


void update(int pos, int val, int l, int r, int rt) {
    if(l == r) {
        tree[rt] = min(tree[rt], val);
        return;
    }
    
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    if (pos <= m) update(pos, val, lson);
    else update(pos, val, rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L > R) return INF;
    if(L <= l && r <= R) {
        return tree[rt];
    } 
    pushDown(rt, l, r);
    int result = INF;
    int m = (l + r) >> 1;
    if(L <= m) result = min(result, query(L, R, lson));
    if(R > m) result = min(result, query(L, R, rson));
    return result;
}

void debugtree(int l, int r, int rt) {
    printf("%d %d %d\n", l, r, tree[rt]);
    if(l == r) return;
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    debugtree(lson);
    debugtree(rson);
}



int dp[MAXN][2];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }

        tree[0] = 0;
        build(1, n, 1);

        // int rotate = 0;
        // for(int i = 1; i <= n; ++i) {
        //     dp[i][0] = dp[i][1] = INF;
        // }
        // dp[0][rotate ^ 1] = 0;

        for(int i = 2; i <= n; ++i) {
            // int tmp = dp[0][rotate ^ 1];
            // for(int j = 1; j <= n; ++j) {
            //     tmp = min(tmp, dp[j][rotate ^ 1] + (j < A[i]));
            // }
            // for(int j = 0; j <= n; ++j) {
            //     dp[j][rotate] = min(INF, dp[j][rotate ^ 1] + (A[i - 1] < A[i]));
            // }
            // dp[A[i - 1]][rotate] = min(dp[A[i]][rotate], tmp);
            // rotate ^= 1;
            // for(int j = 0; j <= n; ++j) { printf("%d ", dp[j][rotate]);  } printf("\n");

            int result = min(tree[0], min(query(1, A[i] - 1, 1, n, 1) + 1, query(A[i], n, 1, n, 1)));
            lazy[1] += (A[i - 1] < A[i]);
            update(A[i - 1], result, 1, n, 1);
            tree[0] += (A[i - 1] < A[i]);
            // debugtree(1, n, 1);
        }

        printf("%d\n", min(tree[0], tree[1] + lazy[1]));

        // result = INF;
        // for(int i = 0; i <= n; ++i) {
        //     result = min(result, dp[i][rotate ^ 1]);
        // }
        // printf("%d\n", result);

    }
    return 0;
}