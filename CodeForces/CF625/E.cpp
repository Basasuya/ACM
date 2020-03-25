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
int A[MAXN], CA[MAXN];
vector<pair<int, int> > B;
// int B[MAXN], CB[MAXN];
int MonX[MAXN], MonY[MAXN], MonZ[MAXN];

const ll lazyDefault = 0;
ll tree[MAXN << 2];
ll lazy[MAXN << 2];

void pushDown(int rt, int l, int r) {
    if(lazy[rt] != lazyDefault) {
        // int m = (l + r) >> 1;
        // int lpart = (r - l + 2) / 2;
        // int rpart = (r - l + 1) / 2;
        tree[rt << 1] = tree[rt << 1] + lazy[rt];
        tree[rt << 1 | 1] = tree[rt << 1 | 1] + lazy[rt];
        
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = lazyDefault;
    }
}

void pushUp(int rt) {
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    lazy[rt] = lazyDefault;
    if(l == r) {
        tree[rt] = -B[l - 1].second;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int L, int R, ll c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        tree[rt] = tree[rt] + c;
        lazy[rt] += c;
        return;
    }
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushUp(rt);
}


int main() {
    int n, m, p;
    while(~scanf("%d %d %d", &n, &m, &p)) {
        map<int, int> mp;
        vector<int> ordA;
        vector<int> ordMon;
        B.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &A[i], &CA[i]);
            ordA.push_back(i);
        }
        
        for(int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            if(mp.find(x) == mp.end()) mp[x] = y;
            else mp[x] = min(mp[x], y);
        }

        for(auto it : mp) {
            B.push_back({it.first, it.second});
        }
        int Bsize = B.size();

        for(int i = 0; i < p; ++i) {
            scanf("%d %d %d", &MonX[i], &MonY[i], &MonZ[i]);
            ordMon.push_back(i);
        }

        auto cmpA = [&](int x, int y) {
            return A[x] < A[y];
        };

        auto cmpMon = [&](int x, int y) {
            return MonX[x] < MonX[y];
        };

        sort(ordA.begin(), ordA.end(), cmpA);
        sort(ordMon.begin(), ordMon.end(), cmpMon);

        build(1, Bsize, 1);
        int MonFlag = 0;
        ll ans = -1e18;
        for(int i = 0; i < n; ++i) {
            debug(A[ordA[i]], CA[ordA[i]]);
            while(MonFlag < p && MonX[ordMon[MonFlag]] < A[ordA[i]]) {
                debug(MonX[ordMon[MonFlag]], MonY[ordMon[MonFlag]], MonZ[ordMon[MonFlag]]);

                int tt = lower_bound(B.begin(), B.end(), make_pair(MonY[ordMon[MonFlag]], INF)) - B.begin();
                if(tt < Bsize) {
                    debug("update", tt + 1, Bsize);
                    update(tt + 1, Bsize, MonZ[ordMon[MonFlag]], 1, Bsize, 1);
                }
                MonFlag ++;
            }
            ans = max(ans, tree[1] - CA[ordA[i]]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}