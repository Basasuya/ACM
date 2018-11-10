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
// const int N = 7005;
const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

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