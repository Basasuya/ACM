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
#include <unordered_map>
using namespace std;
const int N = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

typedef long long ll;

long long l, r; 
int k;
int digit[20];

struct Node{
    ll val;
    ll cnt;
    ll remain;
    Node(ll a=0, ll b=0, ll c=0):val(a), cnt(b), remain(c) {}
}dp[20][1024];
ll ten[20];

Node dfs(int pos, int mask, ll num, bool lead, bool limit) {
    if(pos == -1) return Node(0, 1, 0);
    if(!lead && !limit && dp[pos][mask].val != - 1) return dp[pos][mask];

    ll ans = 0; ll cnt = 0; ll remain = 0;
    int up=limit ? digit[pos]:9;
    
    for(int i = 0; i <= up; ++i) {
        if(lead && i==0) {
            Node callback = dfs(pos-1, mask, num*10, lead, limit && i==digit[pos]); 
            ll val = callback.val; ll count = callback.cnt; ll remain2 = callback.remain;
            // printf("%d\n", count);
            remain = (remain + val + remain2) % MOD; 
        }
        else {
            int tt = mask | (1 << i);
            int ccnt = 0;
            for(int j = 0; j < 10; ++j) {
                if( (tt >> j) & 1 ) 
                    ccnt ++;
            }
            if(ccnt <= k) {
                Node callback = dfs(pos-1, tt, num * 10 + i, lead && i==0, limit && i==digit[pos]); 
                ll val = callback.val; ll count = callback.cnt; ll remain2 = callback.remain;
                // printf("%d\n", count);
                ans = (ans + i * ten[pos] % MOD * count % MOD + val ) % MOD; cnt = (cnt + count) % MOD; remain = (remain + remain2) % MOD;
            }
        }
    }

    dp[pos][mask].val = ans; dp[pos][mask].cnt = cnt; dp[pos][mask].remain = remain;
    return dp[pos][mask];
}


ll solve(ll x) {
    int pos=0;
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 1024; ++j) {
            dp[i][j].val = -1;
            dp[i][j].remain = 0;
            dp[i][j].cnt = 0;
        }
    }

    while(x) {
        digit[pos++]=x%10;
        x/=10;
    }
    Node tt = dfs(pos-1, 0, 0, true, true);
    return (tt.val + tt.remain) % MOD;
}

int main() {
    ten[0] = 1;
    for(int i = 1; i < 19; ++i) ten[i] = ten[i - 1] * 10 % MOD;

    // for(int i = 1; i < 19; ++i) printf("%lld ", ten[i]); printf("\n");
    
    while(~scanf("%lld %lld %d", &l, &r, &k)) {
        printf("%lld\n", (solve(r) - solve(l - 1) + MOD) % MOD);
    }
    return 0;
}