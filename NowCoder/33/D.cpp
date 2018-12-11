#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

int A[N];

int n;
int tree[N];
void add(int pos, int num) {
    for(int i = pos; i <= n; i += i & -i) {
        tree[i] += num;
    }
}
ll sum(int pos) {
    ll ans = 0;
    for(int i = pos; i; i -= i & -i) {
        ans += tree[i];
    }
    return ans;
}
int main() {
    // int n;
    while(~scanf("%d", &n)) {
        memset(tree, 0, sizeof(tree));
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            add(A[i], 1);
            ans += i + 1 - sum(A[i]);
        }
        // printf("HH %d\n", ans);
        ans %= 2;
        int q;
        scanf("%d", &q);    
        while(q --) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            if( ((r - l) % 2 == 1) && (k % 2 == 1) ) ans ^= 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}