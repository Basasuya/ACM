#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int a[N];

ll has[N * 2];
int tot;
int tree[N * 2];
void add(int pos, int num) {
    for (int i = pos; i <= tot; i += i & -i) {
        tree[i] += num;
    }
}
int sum(int pos) {
    int all = 0;
    for (int i = pos; i; i -= i & -i) {
        all += tree[i];
    }
    return all;
}
int main() {
    int n;
    ll t;
    while (~scanf("%d %lld", &n, &t)) {
        multiset<ll> st;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        ll tmp = 0;
        tot = 0;
        for (int i = n - 1; i >= 0; --i) {
            tmp -= a[i];
            has[tot++] = a[i] + tmp;
            has[tot++] = t + tmp;
        }

        sort(has, has + tot);
        tot = unique(has, has + tot) - has;

        tmp = 0;
        ll ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            tmp -= a[i];
            int tt = lower_bound(has, has + tot, a[i] + tmp) - has;
            tt++;
            add(tt, 1);
            //    printf("hh : %lld %d %lld\n", a[i] + tmp, tt, t + tmp);
            tt = lower_bound(has, has + tot, t + tmp) - has;
            ans += sum(tt);

            //    printf("%d %lld\n", tt, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}