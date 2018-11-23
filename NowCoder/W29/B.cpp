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
<<<<<<< HEAD
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
=======
using namespace std;
// const int N = 7005;
const int M = 1e5 + 5;
>>>>>>> 26e32ba06d3e1e8c864089a676f77b78b2121968
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

<<<<<<< HEAD
ll a[N];
ll f(ll x) {
    ll ans = 1;
    while(x) {
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}
int divide(ll k, int d) {
    int cnt = 0;
    while(k % d == 0) {
        cnt ++;
        k /= d;
    }
    return cnt;
}

int mod2, mod3, mod5, mod7;

int main() {
    int n; ll k;
    while(~scanf("%d %lld", &n, &k)) {
        map<tuple<int, int, int, int>, int> mp;
        for(int i = 0; i < n; ++i) {
            ll x; scanf("%lld", &x);
            a[i] = f(x);
        }
        // for(int i = 0; i < n; ++i) printf("%lld ", a[i]); printf("\n");

        ll ans = 0; ll all = 1ll * n * (n - 1) / 2;
        int cnt1 = 0; int cnt0 = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 1) cnt1 ++;
            else if(a[i] == 0) cnt0 ++;
        }
        
        
        
        if(k == 1) {
            printf("%d\n", 0);
            continue;
        }
       
        if(k == 0) {    
            // ans += 1ll * cnt0 * (cnt0 - 1) / 2 + 1ll * cnt0 * (n - cnt0);
            ans += 1ll * cnt1 * (cnt1 - 1) / 2;
            printf("%lld\n", all - ans);
            continue;
        }
        // printf("hhh\n");
        ans += 1ll * cnt0 * (cnt0 - 1) / 2 + 1ll * cnt0 * (n - cnt0);
        // ans += 1ll * cnt1 * (cnt1 + 1) / 2;
        
        k = min(1ll * 130, k);
        // int max2 = -1; int max3 = -1; int max5 = -1; int max7 = -1;
        // printf("%lld %lld\n", ans, all);
        mod2 = divide(k, 2); mod3 = divide(k, 3); mod5 = divide(k, 5); mod7 = divide(k, 7);
        for(int i = 0; i < n; ++i) {
            if(a[i] == 0) continue;
            int D2 = divide(a[i], 2) % k; int D3 = divide(a[i], 3) % k; int D5 = divide(a[i], 5) % k; int D7 = divide(a[i], 7) % k;
            int m2 = (k - D2) % k; int m3 = (k - D3) % k;  int m5 = (k - D5) % k;  int m7 = (k - D7) % k; 
            if(mp.find(make_tuple(m2, m3, m5, m7)) != mp.end()) ans += mp[make_tuple(m2, m3, m5, m7)];   
            
            // printf("%d %d %d %d %d %d %d %d\n", D2, D3, D5, D7, m2, m3, m5, m7);
            // max2 = max(max2, D2); max3 = max(max3, D3); max5 = max(max5, D5); max7 = max(max7, D7);

            if(mp.find(make_tuple(D2, D3, D5, D7)) == mp.end()) {
                mp[make_tuple(D2, D3, D5, D7)] = 1;
            } else mp[make_tuple(D2, D3, D5, D7)] ++;
            
        }
        printf("%lld\n", all - ans);

    }
    return 0;
}
=======
int n;
char seq[M];
// int tree[N];
// void Add(int pos, int num) {
//     for(int i = pos; i <= n; i += i& -i) {
//         tree[i] += num;
//     }
// }
// int Sum(int pos) {
//     int ans = 0;
//     for(int i = pos; i; i -= i & -i) {
//         ans += tree[i];
//     }
//     return ans;
// }
int sum[M];
int main() {    
    while(~scanf("%d %s", &n, seq + 1)) {
        // memset(tree, 0, sizeof(tree));
        memset(sum, 0, sizeof(sum));
        list<int> mst; list<int> sst;
        for(int i = 1; i <= n; ++i) {
            if(seq[i] == 's') sum[i] ++;
        }
        for(int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
        // printf("%d\n", sum[3] - sum[1]);
        ll ans = 0;
        int l = 1; int r = 0;
        for(int i = 1; i <= n; ++i) {
            for(r = r + 1; r <= n; ++r) {
                if(seq[r] == 'm')
                    mst.push_back(r);
                else if(seq[r] == 'c')
                    sst.push_back(r);

                bool flag = false;
                if(mst.size() >= 2 && sst.size() >= 3) {
                    // printf("%d %d\n", l, r);
                    int posm[2];
                    int cnt = 0;
                    for(auto it = mst.begin(); it != mst.end(); it ++, cnt ++) {
                        posm[cnt] = *it;
                        if(cnt == 1) break;
                    }
                    int posc[3];
                    cnt = 2;
                    for(auto it = --sst.end(); ; it --, cnt --) {
                        posc[cnt] = *it;
                        if(cnt == 0) break;
                    }
                    // for(int j = 0; j < 2; ++j) printf("%d ", posm[j]); printf("\n");
                    // for(int j = 0; j < 3; ++j) printf("%d ", posc[j]); printf("\n");
                    if(posm[1] < posc[0]) { //second m to first cc
                        int Sum = sum[posc[2]] - sum[posm[0]];
                        if(Sum > 0) flag = true;
                    } 
                    if(posm[1] < posc[1]) { //second m to last cc
                        int Sum = sum[posc[0]] - sum[posm[0]];
                        if(Sum > 0) flag = true;
                    }
                    if(posm[0] < posc[0]) { // first m to first cc
                        int Sum = sum[posc[2]] - sum[posm[1]];
                        if(Sum > 0) flag = true;
                    }
                }

                if(flag) {
                    ans += n - r + 1;
                    break;
                }
            }
            
            int tt = *mst.begin();
            if(tt == l) mst.erase(mst.begin());
            tt = *sst.begin();
            if(tt == l) sst.erase(sst.begin());

            tt = *(--mst.end());
            if(tt == r) mst.erase(--mst.end());
            tt = *(--sst.end());
            if(tt == r) sst.erase(--sst.end());

            l ++; r --;
            if(r == n) break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
8
mmscccccc
9
mmmscccccc
12
mscmccmscmcc
6
mccmsc
*/
>>>>>>> 26e32ba06d3e1e8c864089a676f77b78b2121968
