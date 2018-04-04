#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

typedef long long LL;

const int MAXN = 100005;

struct Node {
    int p[2];
    int f, l, r;
    int operator[](const int& idx) const { return p[idx]; }
    void input(int idx) {
        scanf("%d%d", &p[0], &p[1]);
        f = idx;
    }
};

Node T[MAXN];
int idx[MAXN];
int cmpw;
int root;
int n;
LL ans;

bool cmp(const Node& a, const Node& b) {
    return a[cmpw] < b[cmpw];
}

int build(int l, int r, int w, int f) {
    int mid = (l + r) >> 1;
    cmpw = w;
    nth_element(T + l, T + mid, T + r + 1, cmp);
    idx[T[mid].f] = mid;
    T[mid].l = l != mid ? build(l, mid - 1, !w, mid) : 0;
    T[mid].r = r != mid ? build(mid + 1, r, !w, mid) : 0;
    return mid;
}

LL dist(LL x, LL y = 0) {
    return x * x + y * y;
}

void query(int o, int w, LL x, LL y) {
    LL tmp = dist(x - T[o][0], y - T[o][1]);
    if (tmp)
        ans = min(ans, tmp);
    if (T[o].l && T[o].r) {
        bool d = !w ? (x <= T[o][0]) : (y <= T[o][1]);
        LL dis = !w ? dist(x - T[o][0]) : dist(y - T[o][1]);
        query(d ? T[o].l : T[o].r, !w, x, y);
        if (dis < ans)
            query(d ? T[o].r : T[o].l, !w, x, y);
    } else if (T[o].l)
        query(T[o].l, !w, x, y);
    else if (T[o].r)
        query(T[o].r, !w, x, y);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        T[i].input(i);
    }
    root = build(1, n, 0, 0);
    for (int i = 1; i <= n; ++i) {
        ans = 9e18;
        query(root, 0, T[idx[i]][0], T[idx[i]][1]);
        printf("%lld\n", ans);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        solve();
    }
    return 0;
}