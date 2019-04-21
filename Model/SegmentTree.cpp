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
#include <string>
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

const int N = 1e5 + 5;
const ll lazyDefault = -1e18;

ll a[N];
ll k[N];
ll kSum[N];
ll tree[N << 2];
ll lazy[N << 2];

void pushUp(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushDown(int rt, int l, int r) {
    if(lazy[rt] != lazyDefault) {
        int m = (l + r) >> 1;
        int lpart = (r - l + 2) / 2;
        int rpart = (r - l + 1) / 2;

        tree[rt << 1] = lpart * lazy[rt] + (kSum[m] - kSum[l - 1]);
        tree[rt << 1 | 1] = rpart * lazy[rt] + (kSum[r] - kSum[m]);
        
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        lazy[rt] = lazyDefault;
    }
}

void build(int l, int r, int rt) {
    lazy[rt] = lazyDefault;
    if(l == r) {
        tree[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

ll query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return tree[rt];
    } 
    pushDown(rt, l, r);
    ll sum = 0;
    int m = (l + r) >> 1;
    if(L <= m) sum += query(L, R, lson);
    if(R > m) sum += query(L, R, rson);
    return sum;
}

void update(int L, int R, ll c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        tree[rt] = (r - l + 1) * c + kSum[r] - kSum[l - 1];
        lazy[rt] = c;
        return;
    }
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushUp(rt);
}

void debug(int l, int r, int rt) {
    printf("%d %d %lld\n", l, r, tree[rt]);
    if(l == r) return;
    pushDown(rt, l, r);
    int m = (l + r) >> 1;
    debug(lson);
    debug(rson);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }

        for(int i = 2; i <= n; ++i) {
            scanf("%lld", &k[i]);
            k[i] += k[i-1];
        }
        for(int i = 2; i <= n; ++i) {
            kSum[i] += kSum[i-1] + k[i];
        }

        build(1,n,1);
        
        int q;
        scanf("%d", &q);
        while(q -- ) {
            char s[10]; int x, y;
            scanf("%s %d %d", s, &x, &y);
            if(s[0] == '+') {
                int l = x; int r = n;
                ll tmp = query(x, x, 1, n, 1);
                while(l <= r) {
                    int m = (l + r) >> 1;
                    ll tmp2 = query(m, m, 1, n, 1);
                    if(tmp2 - tmp - y > k[m] - k[x]) r = m - 1;
                    else l = m + 1;
                }
                // printf("choose: %d\n", r);
                update(x, r, tmp + y - k[x], 1, n, 1);               
            } else {
                printf("%lld\n", query(x, y, 1, n, 1));
            }
            // debug(1, n, 1);
        }
    }
    return 0;
}