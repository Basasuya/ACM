#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;
struct edge{
    long long from;
    long long to;
    long long nxt;
    edge(long long f,long long t,long long n):from(f),to(t),nxt(n){}
};
long long egs[300005];
vector<edge> edges;
void addedge(long long f,long long t){
    edges.emplace_back(f,t,egs[f]);
    egs[f]=edges.size()-1;
}

long long a[300005];
unordered_map<long long,long long> mmp;
long long sumer[300005];
long long sumers;
long long k;
void dfs2(long long num,long long fa,bool flag=false){
    sumer[num]=a[num];
    for(long long i=egs[num];i!=-1;i=edges[i].nxt){
        if(edges[i].to==fa){
            continue;
        }
        dfs2(edges[i].to,num,flag);
        if(sumer[edges[i].to]>0){
            sumer[num]+=sumer[edges[i].to];

        }
    }
    if(!flag && sumers<sumer[num]){
        sumers=sumer[num];
    }
    else if(sumers==sumer[num] && flag){
        k++;
        sumer[num]=0;
    }
}
int main() {
    long long n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(egs,-1,sizeof egs);
    edges.clear();
    bool neg=true;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=0){
            neg=false;
        }
    }
    for(long long i=0;i<n-1;i++){
        long long u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    if(neg){
        long long maxer=-0x3f3f3f3f3f3f3f3f;
        for(long long i=1;i<=n;i++){
            if(mmp.find(a[i])!=mmp.end()){
                mmp[a[i]]++;
            }
            else{
                mmp[a[i]]=1;
            }
            maxer=max(a[i],maxer);
        }
        cout<<maxer*mmp[maxer]<<" "<<mmp[maxer]<<endl;
    }
    else{
        sumers=0;
        k=0;
        dfs2(1,0);
        dfs2(1,0,true);
        cout<<sumers*k<<" "<<k<<endl;
    }
    return 0;
}