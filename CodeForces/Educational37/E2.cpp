#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 6e5+5;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 200005;
set<int>g[maxn];
set<int>vis;    
int u[maxn];
vector<int> result;
int ans;
void dfs(int x){
    u[x]=1;
    vis.erase(x);
    vector<int>ret;
    ans ++;
    for(int p:vis){
        if(!g[x].count(p)){
            ret.push_back(p);
        }
    }
    for(int t:ret){
        vis.erase(t);
    }
    for(int t:ret){
        u[t]=1;
        dfs(t);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i=0;i<n;i++){
        vis.insert(i);
    }
    // int ans = 0;
    for(int i=0;i<n;i++){
        if(!u[i]){
            ans = 0;
            dfs(i);
            result.push_back(ans);
        }
    }

    
    sort(result.begin(), result.end());
    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}