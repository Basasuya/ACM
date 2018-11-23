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

ll a[N];
int main() {
    ll n; int m;
    while(~scanf("%lld %d", &n, &m)) {
        priority_queue<ll>  Q;
        ll all = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%lld", &a[i]);
            // Q.push(x);
            all += a[i];
        }
        if(all != n) {
            printf("ham\n");
            continue;
        }
        bool suc = true;
        sort(a, a + m);
        int pos = m - 1;
        Q.push(n);
        while(!Q.empty()) {
            ll tt = Q.top(); Q.pop();
            if(pos == -1) {
                suc = false; break;
            }
            if(tt > a[pos]) {
                Q.push(tt / 2); Q.push(tt - tt / 2);
            } else if(tt < a[pos]) {
                suc = false; break;
            } else {
                pos --;
            }
        }
        suc &= pos == -1;
        // 
        // while(Q.size() > 1) {
        //     ll t1 = Q.top(); Q.pop(); ll t2 = Q.top(); Q.pop();
        //     // printf("%lld %lld\n", t1, t2);
        //     if(t2 - t1 > 1) { suc = false; break; }
        //     Q.push(t1 + t2);
        //     if(t1 + t2 > n || t1 + t2 < 0) { suc = false; break; }
        // }
        // ll t1 = Q.top(); 
        // suc &= t1 == n;
        printf("%s\n", suc ? "misaka" : "ham");

    }
    return 0;
}

/*

4 2
3 1

9 4
2 2 2 3
*/