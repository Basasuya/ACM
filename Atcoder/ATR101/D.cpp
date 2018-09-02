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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

int A[N];
int B[N];
int C[N];
ll tree[N * 2];
int n;
void Add(int pos, int num) {
    for (int i = pos; i <= 2 * n; i += i & -i) tree[i] += num;
}
ll Sum(int pos) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) ans += tree[i];
    return ans;
}

bool solve(int x) {
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; ++i) {
        if (A[i] >= x)
            C[i] = 1;
        else
            C[i] = -1;
    }
    ll ans = 0;
    Add(n, 1);
    for (int i = 1; i <= n; ++i) {
        C[i] += C[i - 1];
        ans += Sum(C[i] + n);
        Add(C[i] + n, 1);
    }
    //    printf("%d\n", ans);
    return (ans >= (1ll * n * (n + 1) / 4));
}
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
            B[i] = A[i];
        }
        sort(B + 1, B + n + 1);
        int tot = unique(B + 1, B + n + 1) - B - 1;
        int l = 1;
        int r = tot;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (solve(B[mid]))
                l = mid + 1;
            else
                r = mid - 1;
        }
        //    for(int i = 1; i <= tot; ++i) printf("%d ", B[i]); printf("\n");
        printf("%d\n", B[r]);
    }
    return 0;
}