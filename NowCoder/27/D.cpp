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
typedef long long ll;
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 2333;

char seq[N];
int prefix[N];

int dp[2][N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        scanf("%s", seq + 1);
        
        prefix[0] = 0;
        for(int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1] + (seq[i] == '(' ? 1 : -1);
        }

        if(prefix[n] != 0) {
            printf("0\n");
            continue;
        }


        int flag = 1;
        int ed = 0;
        dp[flag][0] = 1;

        for(int i = 1; i <= n; ++i) {
            if(seq[i] == '(') {
                dp[flag ^ 1][ed + 1] = dp[flag][ed];
                dp[flag ^ 1][0] = dp[flag][0];
                for(int j = ed; j >= 1; --j) {
                    dp[flag ^ 1][j] = (dp[flag][j - 1] + dp[flag][j]) % MOD;
                }
                ed ++;
            } else {
                for(int j = ed; j >= 0; --j) {
                    dp[flag ^ 1][j] = dp[flag][j + 1];
                    if(prefix[i] - j>= 0) dp[flag ^ 1][j] = (dp[flag][j] + dp[flag ^ 1][j]) % MOD;
                }
            }
            flag ^= 1;

        //    for(int j = 0; j <= ed; ++j) printf("%d ", dp[flag][j]); printf("\n");
        }
        // int ans = 0;
        // for(int i = 0; i <= ed; ++i) {
        //     ans = (ans + dp[flag][0]) % MOD;
        // }

        printf("%d\n", dp[flag][0]);
    }
    return 0;
}