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
const int N = 5e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int a[N];
int suf[N], pre[N];
int dp[N]; int last[N];
int main() {
    int n, c;
    while(~scanf("%d %d", &n, &c)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i) {
            pre[i] += pre[i-1];
            if(a[i] == c) pre[i] ++; 
        }

        for(int i = n; i >= 1; --i) {
            suf[i] += suf[i+1];
            if(a[i] == c) suf[i] ++; 
        }

        for(int i = 1; i <= n; ++i) {
            dp[i] = pre[i-1] + 1;
            int prePos = last[a[i]];
            if(prePos)
                dp[i] = max(dp[i], dp[prePos] + 1);
            last[a[i]] = i;
        }   

        int ans = -1;
        for(int i = 0; i <= n; ++i) {
            ans = max(ans, dp[i] + suf[i + 1]);
        }

        printf("%d\n", ans);
    }
    return 0;
}