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
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;


int n;
int A[N];
vector<int> vc[M];
int maxx;
int solve(ll x, int pos) {
    if(x > maxx) return 0;
    int tt = (lower_bound(vc[x].begin(), vc[x].end(), pos) - vc[x].begin());
    return vc[x].size() - tt;
}
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    // vector<int> t1;
    // t1.push_back(1); t1.push_back(2);
    // int tt = (lower_bound(t1.begin(), t1.end(), -1) - t1.begin());
    // printf("%d\n", tt);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_){
        for(int i = 0; i < M; ++i) vc[i].clear();
        scanf("%d", &n);
        maxx = -1;
        for(int i = 1; i <= n; ++i) {
            scanf("%d",  &A[i]);
            vc[A[i]].push_back(i);
            maxx = max(maxx,  A[i]);
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if(A[i] == 0 && A[j] == 0) ans += n - j;
                else if(A[i] == 0 || A[j] == 0) ans += solve(0, j + 1);
                else {
                    int pre = -1;
                    if(A[i] % A[j] == 0) ans += solve(A[i] / A[j], j+1), pre = A[i] / A[j];
                    if(A[j] % A[i] == 0 && pre != A[j] / A[i]) ans += solve(A[j] / A[i], j+1), pre = A[j] / A[i];
                    if(pre != 1ll * A[j] * A[i]) ans += solve(1ll * A[j] * A[i], j+1);
                }
            }
        }

        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}