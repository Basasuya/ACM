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

int n, s;
const int N = 1e5 + 5;
int A[N];  // origin input array
vector<int> pos[N]; // positions in initial array split by its value
int nowSize[N]; // the order of A[i] in their own position array 
int input[N]; // use for segment tree input

int maxx[N << 2];
int lazy[N << 2];

void pushUp(int rt) {
    maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
}

void pushDown(int rt) {
    if(lazy[rt]) {
        maxx[rt << 1] += lazy[rt];
        maxx[rt << 1 | 1] += lazy[rt];
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if(l == r) {
        maxx[rt] = input[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson); build(rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return maxx[rt];

    pushDown(rt);
    int m = (l + r) >> 1;
    int ret = -1;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
} 

void update(int c, int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        maxx[rt] += c;
        lazy[rt] += c;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(c, L, R, lson);
    if(R > m) update(c, L, R, rson);
    pushUp(rt);
}


int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        scanf("%d %d", &n, &s);
        for(int i = 0; i < N; ++i) pos[i].clear();
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);

        for(int i = 1; i <= n; ++i) {
            pos[A[i]].push_back(i);
            nowSize[i] = pos[A[i]].size();
        }

        for(int i = 0; i < N; ++i) pos[i].push_back(n + 1);
        input[0] = 0;
        for(int i = 1; i <= n; ++i) {
            input[i] = input[i-1] + 1;
            if(nowSize[i] == s + 1) input[i] -= s + 1;
            else if(nowSize[i] > s + 1) input[i] --;
        }
        build(1, n, 1);
        int ans = -1;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, query(i, n, 1, n, 1));
            int num = A[i];
            if(nowSize[i] + s < pos[num].size()) {
                int tmp = pos[num][nowSize[i] + s - 1];
                int tmp2 = pos[num][nowSize[i] + s];

                update(-1, i, tmp - 1, 1, n, 1);
                update(s, tmp, tmp2 - 1, 1, n, 1);
            } else {
                update(-1, i, n, 1, n, 1);
            }
        }

        printf("Case #%d: %d\n", cas, ans);

    }
    return 0;
}