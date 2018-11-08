
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
const int maxn = 1e5 + 5;
const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long LL;

LL f[maxn], g[maxn];
vector<LL> v[maxn];
 
LL qpow(LL x, LL fa, LL mod){
  LL res = 1;
  while(fa){
    if(fa % 2 == 1) res = res * x % mod;
    x = x * x % mod;
    fa /= 2;
  }
  return res;
}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  LL n; cin >> n;
  for(LL i = 1; i <= 1e5; i++){
        for(LL j = i; j <= 1e5; j += i) v[j].push_back(i);
    }
    int maxx = -1;
    // for(int i = 1; i <= 1e5; ++i) {
    //     maxx = max(maxx, (int)v[i].size());
    //     printf("%d ", v[i].size()); 
    // }
    // printf("\n\n%d\n", maxx);
  while(n--){
    LL x, k, p; cin >> x >> k >> p;
    LL ans = 0;
    for(LL i = 0; i < LL(v[x].size()); i++) f[v[x][i]]++;
    // memset(g, 0, sizeof(g))
    for(LL i = LL(v[x].size()) - 1; i >= 0; i--){
        LL y = v[x][i]; g[y] += f[y];
        if(g[y] <= 0) continue;
        ans = (ans + qpow(y, k, p) * g[y] % p) % p;
        for(LL j = 0; j < LL(v[y].size()); j++) g[v[y][j]] -= g[y];
    }
    // for(int i = 1; i <= 1e5; i += 100) printf("%lld ", g[i]); printf("\n");
    cout << ans << "\n";
  }
  return 0;
}