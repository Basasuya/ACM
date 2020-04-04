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
const int N = 4e5 + 5;
const int MM = 1e5 + 5;
// const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;
struct Node{
    int num, offset;
    Node(int a=0, int b=0):num(a), offset(b) {}
    bool operator < (const Node &T) const {
        if(num != T.num) return num < T.num;
        else return offset < T.offset;
        ///
    }
};
struct Tode{
    ll sum; int val; int len; int now;
    Tode(ll a=0, int b=0, int c=0, int d=0):sum(a), val(b), len(c), now(d){}
    bool operator < (const Tode &T) const {
        if(sum != T.sum) return sum < T.sum;
        else return 1;
        ///
    }
};

int n, q;
ll X[N], Y[N], A[5], B[5], C[5], M[5];
ll Z[MM];
Node seq[N * 2];
Tode prefix[N * 2];
ll hhh[N * 2];

int main() {
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("B-small-attempt4.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_){
        scanf("%d %d", &n, &q);
        scanf("%lld %lld %lld %lld %lld %lld", &X[1], &X[2], &A[1], &B[1], &C[1], &M[1]);
        scanf("%lld %lld %lld %lld %lld %lld", &Y[1], &Y[2], &A[2], &B[2], &C[2], &M[2]);
        scanf("%lld %lld %lld %lld %lld %lld", &Z[1], &Z[2], &A[3], &B[3], &C[3], &M[3]);

        for(int i = 3; i <= n; ++i) {
            X[i] = (A[1] * X[i - 1] + B[1] * X[i - 2] + C[1]) % M[1];
            Y[i] = (A[2] * Y[i - 1] + B[2] * Y[i - 2] + C[2]) % M[2];
        }
        for(int i = 3; i <= q; ++i) {
            Z[i] = (A[3] * Z[i - 1] + B[3] * Z[i - 2] + C[3]) % M[3];
        }
        for(int i = 1; i <= n; ++i) {
            X[i] ++; Y[i] ++;
        }
        for(int i = 1; i <= q; ++i) Z[i] ++;

        int tot = 0;
        ll tt = 0;
        for(int i = 1; i <= n; ++i) {
            if(X[i] > Y[i]) swap(X[i], Y[i]);
            // printf("%lld %lld\n", X[i], Y[i]);
            tt += Y[i] - X[i] + 1;
            seq[tot ++ ] = Node(X[i], 1);
            seq[tot ++ ] = Node(Y[i] + 1, -1);
        }
        // printf("%lld\n", tt);

        sort(seq, seq + tot);

        // for(int i = 0; i < tot; ++i) printf("%d %d : ", seq[i].num, seq[i].offset); printf("\n");
        // seq[tot] = Node(seq[tot - 1].num + 1, 0); 
        int tmp = 0;
        int tot2 = 0;
        ll all = 0;
        for(int i = 1; i < tot; ++i) {
            tmp += seq[i-1].offset;
            if(seq[i].num != seq[i-1].num) {
                int tt = seq[i].num - seq[i - 1].num;
                prefix[tot2] = Tode(all, tmp, tt, seq[i-1].num);
                // if(seq[i-1].num < 0) printf("hhh");
                hhh[tot2 ++] = all;
                // printf("%lld %d %d from %d to %d\n", all, tmp, tt, seq[i-1].num, seq[i].num);
                all += 1ll * tt * tmp;
            }
        }
        // printf("%lld\n", all);

        ll ans = 0;
        for(int i = 1; i <= q; ++i) {
            // printf("hhh: %lld\n", Z[i]);
            Z[i] = tt - Z[i] + 1;
            if(Z[i] <= 0) continue;
            // Z[i] = 1;
            // printf("hhh: %lld\n", Z[i]);
            int pos = lower_bound(hhh, hhh + tot2, Z[i]) - hhh;
            pos --;
            ll lef = Z[i] - prefix[pos].sum;
            // printf("%d %d %lld\n", pos, prefix[pos].now, lef);
            ll tt = prefix[pos].now + lef / prefix[pos].val ;
            if(lef && (lef % prefix[pos].val == 0) ) tt --;
            // printf("%lld\n", tt);
            ans += 1ll * tt * i;
        }

        printf("Case #%d: %lld\n", _, ans);
    }

    return 0;
}

/*

3
5 5
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42


3
5 1
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
5 5
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
1 2
0 0 0 0 0 1
0 0 0 0 0 1
0 1 0 0 0 2

100
1 2
0 0 0 0 0 1
0 0 0 0 0 1
0 1 0 0 0 2

100
55769 1
0 0 0 0 0 1000000000
999999999 999999999 0 0 999999999 1000000000
2512670 116262940 14464944 27962747 49835299 118572793


400000 1
97295458 97277314 13871606 251023440 11331260 274678035
97295458 97277314 13871606 251023440 11331260 274678035
244442 258459 136705 290087 276595 400000
*/