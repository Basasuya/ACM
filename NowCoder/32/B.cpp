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
const int MOD = 1e9 + 7;
typedef long long ll;

struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
int dp[N]; int son[N];
int A[N];
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int ans;
void dfs(int x, int pre) {
    dp[x] = 0; son[x] = 1;
    int tmpAns = A[x]; int tmpCnt = 1;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int y = E[i].to; if(y == pre) continue;
        dfs(y, x);
        son[x] += son[y];
        dp[x] ^= ( (son[y] % 2) ? A[x] : 0 ) ^ dp[y];
        ans ^= ( (tmpCnt % 2) ? dp[y] : 0 ) ^ ( (son[y] % 2) ? tmpAns : 0);
        // printf("%d\n", tmpCnt);
        // printf("%d %d %d\n", x, y, ( (tmpCnt % 2) ? dp[y] : 0 ) ^ ( (son[y] % 2) ? tmpAns : 0));
        // printf("pre %d %d %d %d ", tmpAns, dp[y], tmpCnt, ( (tmpCnt % 2) ? dp[y] : 0 ));
        tmpAns ^= ( (son[y] % 2) ? A[x] : 0 ) ^ dp[y];
        tmpCnt += son[y];
        // printf("%d\n", tmpAns);
    }
    dp[x] ^= A[x];
    // ans ^= dp[x] ^ A[x];
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(head, -1, sizeof(head)); tot = 0;
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
        
        dfs(1, 1);
        // for(int i = 1; i <= n; ++i) printf("%d ", dp[i]); printf("\n");
        printf("%d\n", ans);
    }
    return 0;
}

/*

4
1 2
1 3
1 4
1 2 3 4

*/