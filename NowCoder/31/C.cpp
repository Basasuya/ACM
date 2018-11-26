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
#define INF 0x3f3f3f3f
#define pi 3.141592653589793
#define mod 998244353
#define LL long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sf(x) scanf("%d",&x)
#define sc(x,y,z) scanf("%d%d%d",&x,&y,&z)
 
using namespace std;
 
const int N = 21;
 
map<vector<int>,int> mp;
int n,inv[N]; bool v[N];
vector<int> a;
 
inline void init()
{
    inv[1]=1;
    for(int i=2;i<N;i++)
        inv[i]=(mod-mod/i)*(LL)inv[mod%i]%mod;
}
 
int dfs(vector<int> a)
{
    if (mp[a]) return mp[a];
    vector<int> b; b.resize(n);
    int ans=0,t=0;
    for(int i=0;i<n;i++)
    {
        if (v[i]) {t++;continue;}
        int l=0,r=i+1;b[i]=i;
        for(int j=0;j<n;j++)
            if (a[j]<i) b[l++]=a[j];
            else if (a[j]>i) b[r++]=a[j];
        v[i]=1;
        if (a==b) t++;
        else ans=(ans+(LL)dfs(b)*inv[n]%mod)%mod;
        v[i]=0;
    }
    return mp[a]=(LL)(ans+1)*n%mod*inv[n-t]%mod;
}
 
int main()
{
    init(); sf(n);
    a.resize(n);
    for(int i=0;i<n;i++) sf(a[i]),a[i]--;
    printf("%d\n",dfs(a));
    return 0;
}
