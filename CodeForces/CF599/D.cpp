#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
set<int>g[maxn];
set<int>vis;
int u[maxn];
void dfs(int x){
    u[x]=1;
    vis.erase(x);
    vector<int>ret;
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
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!u[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans-1<<endl;
}