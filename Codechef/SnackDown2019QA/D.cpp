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
int B[N];
int main() {
    int T;
    int n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &B[i]);

        bool suc = true;
        int dp[4];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n && suc; ++i) {
            dp[1] = B[i] - A[i] - dp[1] - dp[2]*2 - dp[3]*3;
            if(dp[1] < 0) suc = false;
            // if(dp[3] != 0) suc = false;
            dp[3] = 0;
            swap(dp[3], dp[2]);
            swap(dp[2], dp[1]);
        }
        if(dp[2] != 0 || dp[3] != 0) suc = false;

        printf("%s\n", suc ? "TAK" : "NIE");
    }
    return 0;
}