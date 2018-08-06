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
const int N = 5005;
const int INF = 0x3f3f3f3f;

int h[N];
int dp[N][N][3];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        memset(dp, INF, sizeof(dp));

        dp[0][0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= (i+1)/2; ++j) {
                dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]);
                dp[i][j][1] = dp[i-1][j][2] + max(0, h[i] - h[i-1] + 1);
                if(j)
                    dp[i][j][2] = min(dp[i-1][j-1][0] + max(0, h[i-1] - h[i] + 1), dp[i-1][j-1][1] + max(0,min(h[i-2]-1,h[i-1])-h[i]+1) );
            }
        }

        int ed = (n+1) / 2;
        
        for(int i = 1; i <= ed; ++i) {
        //    printf("%d hh, %d ",i,  ed);
            printf("%d ", min(min(dp[n][i][0], dp[n][i][1]), dp[n][i][2]) );
        }
        printf("\n");
    }
    return 0;
}