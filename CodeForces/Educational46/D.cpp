#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
const int N = 1e3 + 5;
typedef long long ll;
using namespace std;
const int MOD = 998244353;
int A[N];
ll dp[N];
ll C[N][N];


int main() {
    int n;
    C[0][0] = 1;
    for(int i = 1; i < N; ++i) {
        C[i][0] = 1; C[i][i] = 1;
        for(int j = 1; j <= i/2; ++j) {
            C[i][j] = C[i][i-j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }

    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[n + 1] = 1;
        for(int i = n; i >= 1; --i) {
            int edpos = i + A[i] + 1;

            if(A[i] > 0 && edpos <= n+1) {
                for(int j = edpos; j <= n+1; ++j) {
                //    printf("%d %d\n", i, j);
                    dp[i] = (dp[i] + C[j - i - 1][A[i]] * dp[j] % MOD ) % MOD;
                }
            } 
       //     printf("hh %d %d\n", i, dp[i]);
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}