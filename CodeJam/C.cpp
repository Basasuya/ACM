/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=105;
int money[70005];
int Tx,Ty,Sx,Sy,T,n,m,cnt;
int a[maxn][maxn],label[maxn][maxn],bg;
bool vis[maxn][maxn],canend[70005],canarr[70005];
vi g[16];
vector< pii > reach;

bool legal1(int x,int y,int mask)
{
    if(x<1 || x>n || y<1 || y>m)return false;
    if(a[x][y]<=-100000)return false;
    if(a[x][y]>=0 || ((mask>>(label[x][y]-1))&1))return true;
    return false;
}

bool legal2(int x,int y,int mask)
{
    if(x<1 || x>n || y<1 || y>m)return false;
    if(a[x][y]<=-100000)return false;
    return true;
}

bool DFS(int x,int y,int mask)
{
    if(!legal1(x,y,mask) || vis[x][y])return false;
    //if(mask==0)printf("%d %d\n",x,y);
    vis[x][y]=true;
    if(a[x][y]>0)money[mask]+=a[x][y];
    if(a[x][y]<0)money[mask]+=a[x][y];
    bool flag=false;
    if(x==Tx && y==Ty)flag=true;
    flag|=DFS(x+1,y,mask);
    flag|=DFS(x-1,y,mask);
    flag|=DFS(x,y+1,mask);
    flag|=DFS(x,y-1,mask);
    return flag;
}

void findreach(int x,int y,int mask)
{
    if(!legal2(x,y,mask) || vis[x][y])return;
    vis[x][y]=true;
    if(a[x][y]<0 && a[x][y]>-100000 && ((mask>>(label[x][y]-1))&1)==0)
    {
        reach.pb(mp(x,y));
        return;
    }
    findreach(x+1,y,mask);
    findreach(x-1,y,mask);
    findreach(x,y+1,mask);
    findreach(x,y-1,mask);
}

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&n,&m,&bg);
        scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
        cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                label[i][j]=0;
                scanf("%d",&a[i][j]);
                if(a[i][j]<0 && a[i][j]>-100000)label[i][j]=++cnt;
            }
        int ans=-1;
        for(int mask=0;mask<(1<<cnt);mask++)money[mask]=bg,canend[mask]=canarr[mask]=false;
        for(int mask=0;mask<(1<<cnt);mask++)
        {
            //money[mask]=0;cost[mask]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    vis[i][j]=false;
            canend[mask]=DFS(Sx,Sy,mask);
        }   
        for(int i=0;i<=cnt;i++)g[i].clear();
        for(int mask=0;mask<(1<<cnt);mask++)
        {
            int cc=0;
            for(int j=0;j<cnt;j++)if((mask>>j)&1)cc++;
            g[cc].pb(mask);
        }
        canarr[0]=true;
        if(canend[0])ans=max(ans,money[0]);
        for(int cc=0;cc<=cnt;cc++)
            for(int p : g[cc])
            {
                if(!canarr[p])continue;
                if(canend[p])ans=max(ans,money[p]);
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        vis[i][j]=false;
                reach.clear();
                findreach(Sx,Sy,p);
                for(pii s : reach)
                {
                    if(money[p]+a[s.fi][s.se]<0)continue;
                    //printf("%d %d %d\n",s.fi,s.se,label[s.fi][s.se]);
                    int mask=p|(1<<(label[s.fi][s.se]-1));
                    canarr[mask]=true;
                }
            }
        prr(cas);printf("%d\n",ans);
        cerr<<cas<<endl;
        if(cas==4)cerr<<"!!!"<<ans<<endl;
    }
    return 0;
}
