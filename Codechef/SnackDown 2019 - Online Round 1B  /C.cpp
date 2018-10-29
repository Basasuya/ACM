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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int A[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m, k, l;
        scanf("%d %d %d %d", &n, &m, &k, &l);
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        sort(A, A+n);
        ll initWaitTime = 1ll * (m + 1)* l;
        ll ans = INF;
        for(int i = 0; i < n; ++i) {
            ll tmpAns = max(initWaitTime - A[i], 0ll);

            if(initWaitTime < A[i]) initWaitTime = A[i];
            initWaitTime += l;
            ans = min(ans, tmpAns);
        }
        ans = min(max(initWaitTime - k, 0ll), ans);


        printf("%lld\n", ans);
    }
    return 0;
}