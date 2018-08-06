#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
const ll INF = 1e18;
int A[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < 2*n; ++i) {
            scanf("%d", &A[i]);
        }
        sort(A, A+2*n);

        ll ans = INF;
        for(int i = 0; i <= n; ++i) {
            int t1 = A[i + n - 1] - A[i];
            int t2;
            if(i == 0) t2 = A[2*n-1] - A[n];
            else if(i == n) t2 = A[n-1] - A[0];
            else t2 = A[2*n-1] - A[0];
            ans = min(ans, 1ll*t1*t2);
        }

        printf("%lld\n", ans);
    }
    return 0;
}