#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
const int N = 3005;
typedef long long ll;

struct Node{
    int p;
    int c;
}E[N];
int cnt[N];
ll sum[N][N];
int Rank[N][N];
int Ed[N];
// vector<Node> vc[N];
bool cmp(Node &A, Node &B) {
    return A.c == B.c? cnt[A.p] > cnt[B.p] : A.c < B.c; 
}
int has[N];



int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        ll ans = 1e18;
        memset(cnt, 0, sizeof(cnt));
        memset(has, 0, sizeof(has));
        
        for(int i = 1; i <= m; ++i) sum[i][0] = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &E[i].p, &E[i].c);
            cnt[E[i].p] ++;
        }
        sort(E, E+n, cmp);
        for(int i = 0; i < n; ++i) {
            if(sum[E[i].p][0] == 0) sum[E[i].p][1] = E[i].c, Rank[E[i].p][1] = i, sum[E[i].p][0] ++;
            else sum[E[i].p][sum[E[i].p][0] + 1] = sum[E[i].p][sum[E[i].p][0]] + E[i].c, Rank[E[i].p][sum[E[i].p][0] + 1] = i, sum[E[i].p][0] ++;
        }
        // for(int i = 1; i <= m; ++i) {
        //     for(int j = 1; j <= sum[i][0]; ++j) {
        //         printf("%d ", sum[i][j]);
        //     }
        //     printf("\n");
        // }

        for(int i = max(cnt[1], 1); i <= n; ++i) {
            ll all = 0; int tmp = 0;
            for(int j = 2; j <= m; ++j) {
                if(cnt[j] >= i) {
                    int ed = cnt[j] - i + 1;
                    all += sum[j][ed];
                    tmp += ed;
                    has[j] = i + 1;
                    Ed[j] = Rank[j][ed];
                }
            }
            int lef = i - cnt[1] - tmp;
        //   printf("%d %d %lld %d %lld\n", lef, tmp, all, i, ans);
            if(lef < 0) {
            //    ans = min(ans, all);
                continue;
            }
            for(int j = 0; j < n; ++j) {
                if(lef == 0) break;
                if(E[j].p == 1 || ( (has[E[j].p] == i + 1) && (j <= Ed[E[j].p]) ) ) continue;
                all += E[j].c;
                lef --;
            }

            if(lef == 0) ans = min(ans, all);
        }

        printf("%lld\n", ans);
    }
    return 0;
}