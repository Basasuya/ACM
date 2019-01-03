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
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int a[N];
char seq[N];

int dp[N];
int dp2[N];

ll suf[N][4];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq + 1);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);

        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            if(seq[i] == 'h' && dp[i-1] == 0) dp[i] = 1;
            else if(seq[i] == 'a' && dp[i-1] == 1) dp[i] = 2;
            else if(seq[i] == 'r' && dp[i-1] == 2) dp[i] = 3;
            else if(seq[i] == 'd' && dp[i-1] == 3) dp[i] = 4;
            else dp[i] = dp[i-1];
        }
        
        dp2[n + 1] = 5;
        for(int i = n; i >= 1; --i) {
            if(seq[i] == 'd' && dp2[i+1] == 5) dp2[i] = 4;
            else if(seq[i] == 'r' && dp2[i+1] == 4) dp2[i] = 3;
            else if(seq[i] == 'a' && dp2[i+1] == 3) dp2[i] = 2;
            else if(seq[i] == 'h' && dp2[i+1] == 2) dp2[i] = 1;
            else dp2[i] = dp2[i+1];
        }

        for(int i = 1; i <= n; ++i) {
            if(seq[i] == 'h') suf[i][0] = a[i];
            else if(seq[i] == 'a') suf[i][1] = a[i];
            else if(seq[i] == 'r') suf[i][2] = a[i];
            else if(seq[i] == 'd') suf[i][3] = a[i];
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 4; ++j) {
                suf[i][j] += suf[i - 1][j];
            }
        }
        // for(int i = 1; i <= n; ++i) printf("%d ", dp[i]); printf("\n");
        // for(int i = 1; i <= n; ++i) printf("%d ", dp2[i]); printf("\n");

        ll ans = 1e18;
        for(int i = n; i >= 1; --i) {
            if(dp2[i] == 1) {
                ans = min(ans, suf[i][0]);
                break;
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(dp[i] == 4) {
                ans = min(ans, suf[n][3] - suf[i-1][3]);
                break;
            }
        }

        // printf("%lld\n", ans);
        int pos1 = -1; int pos2 = -1;
        for(int i = n; i >= 1; --i) {
            if(dp2[i] == 2) {
                pos2 = i;
                break;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(dp[i] == 2) {
                pos1 = i;
                break;
            }
        }
        if(pos1 == -1 || pos2 == - 1 || pos1 > pos2) ans = 0;
        else ans = min(ans, suf[pos2][1] - suf[pos1 - 1][1]);

        pos1 = -1; pos2 = -1;
        for(int i = n; i >= 1; --i) {
            if(dp2[i] == 3) {
                pos2 = i;
                break;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(dp[i] == 3) {
                pos1 = i;
                break;
            }
        }
        if(pos1 == -1 || pos2 == - 1 || pos1 > pos2) ans = 0;
        else ans = min(ans, suf[pos2][2] - suf[pos1 - 1][2]);

        printf("%lld\n", ans);       
    }
    return 0;
}