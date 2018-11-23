#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100000+5;
string ch[maxn];
struct BPM{
    int n,m;
    vector<int> G[maxn];
    int left[maxn];//left[i]为右边第i个点的匹配编号，-1表示不存在
    bool T[maxn];//T[i]为右边第i个点是否已标记
 
    int right[maxn];//求最小覆盖用
    bool S[maxn];//求最小覆盖用
 
    void init(int n,int m)
    {
        this->n=n;
        this->m=m;
        for(int i=1;i<=n;i++) G[i].clear();
    }
 
    void addedge(int u,int v) {G[u].push_back(v);}
 
    bool match(int u)
    {
        S[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(!T[v])
            {
                T[v]=true;
                if(left[v]==-1||match(left[v]))
                {
                    left[v]=u;
                    right[u]=v;
                    return true;
                }
            }
        }
        return false;
    }
    //求最大匹配
    int solve(){
        memset(left,-1,sizeof(left));
        memset(right,-1,sizeof(right));
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(S,0,sizeof(S));
            memset(T,0,sizeof(T));
            if(match(i)) ans+=1;
        }
        return ans;
    }
    //求最小覆盖，X和Y未最小覆盖的点集
    int mincover(vector<int> &X,vector<int> &Y)
    {
        int ans=solve();
        memset(S,0,sizeof(S));
        memset(T,0,sizeof(T));
        for(int i=1;i<=n;i++)
            if(right[i]==-1) match(i);//从所有X未盖点出发
        for(int i=1;i<=n;i++) 
            if(!S[i]) X.push_back(i);//X中未标记点
        for(int i=1;i<=m;i++) 
            if(T[i]) Y.push_back(i);//Y中标记点
        return ans;
    }
};
BPM solver;
int main()
{
    int r,c,m;
    scanf("%d%d",&r,&c);
    {
    	for(int i = 0 ; i < r ; i++) cin>>ch[i];
        solver.init(r,c);
        for(int i = 0 ; i < r ; i++)
		{
        	for(int j = 0 ; j < c ; j++)
        	{
        		if(ch[i][j] == '*') solver.addedge(i+1,j+1);
			}
        }
        vector<int> X,Y;
        int ans=solver.mincover(X,Y);
        printf("%d\n",ans);
        printf("%d ",X.size());
        for(int i=0;i<X.size();i++) printf("%d ",X[i]);puts("");
        printf("%d ",Y.size());
        for(int i=0;i<Y.size();i++) printf("%d ",Y[i]);puts("");
    }
}
