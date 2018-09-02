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
const int N = 5005;
int mod;
int ans[N];
int Pow(int x, int q) {
    int ans = 1;
    while(q) {
        if(q & 1)
            ans = 1ll* ans *x %mod; 
        x = 1ll*x*x % mod;
        q >>= 1;
    }
    return ans;
}
int main() {
    int T, q;
    scanf("%d %d", &T, &q);
    mod = q;
    ans[1] = 1;
    for(int i = 2; i < N; ++i) {
        ans[i] = 1ll* ans[i-1] * (4*i - 2) % mod * Pow(i+1, mod - 2) % mod;
    }
    for(int cas = 1; cas <= T; ++cas) {
        int n, q1, q2, q3;
        scanf("%d %d %d %d", &n, &q1, &q2, &q3);
        for(int i = 1; i <= n; ++i) {

        }
        printf("Case #%d: %d\n", cas, ans[n]);
    }
}

// int a[N];
// int main() {
//     int n, q1, q2, q3;
//     while(~scanf("%d %d %d %d", &n, &q1, &q2, &q3)) {
//         for(int i = 1; i <= n; ++i) {
//             a[i] = i;
//         }

//         int t1 = q1 - q2; int t2 = q1 - q3; int t3 = q2 - q3;
//         int ans = 0;
//         do {
//             bool flag = true;
//             for(int i = 1; i <= n && flag; ++i) {
//                 for(int j = i + 1; j <= n && flag; ++j) {
//                     for(int k = j + 1; k <= n && flag; ++k) {
//                         if( (a[i] - a[j])*t1 > 0 && (a[i] - a[k])*t2 > 0 && (a[j] - a[k])*t3 > 0) flag = false;
//                     }
//                 }
//             }
//             if(flag) ans ++;
//         }  while(next_permutation(a+1, a+n+1));
//         printf("%d\n", ans);
//     }
//     return 0;
// }