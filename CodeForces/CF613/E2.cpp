#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int maxn=2e5+7;
int n,m;
struct segment
{
    int L,R;
}a[maxn];
bool cmp1(const segment &x,const segment &y)
{
    return x.L<y.L;
}
struct border
{
    int p,id,flag;
}b[2*maxn];
bool cmp2(const border &x,const border &y)
{
    return x.p<y.p;
}
map<int,int> Lb;
int init()
{
    int cnt=0;
    Lb.clear();
    int L,R=-INF;
    for(int i=1;i<=n;i++)
    {
        if(a[i].L>R)
        {
            if(R!=-INF)
                Lb[L]=0;
            cnt++;
            L=a[i].L,R=a[i].R;
        }
        else
            R=max(R,a[i].R);
    }
    Lb[L]=0;
    return cnt;
}
int ans[maxn];
void process()
{
    set<int> open;
    for(int i=1;i<=m;i++)
    {
        vector<int> op,cl;
        int j=i;
        do
        {
            if(b[j].flag==-1)
                op.push_back(b[j].id);
            else
                cl.push_back(b[j].id);
            j++;
        }while(j<=m&&b[j].p==b[i].p);
        if(open.size()==1&&!op.empty())
            ans[*open.begin()]++;
        for(auto it:op)
            open.insert(it);
        for(auto it:cl)
            open.erase(it);
        i=j-1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].L,&a[i].R);
        sort(a+1,a+n+1,cmp1);
        int cur=init();
        m=0;
        for(int i=1;i<=n;i++)
        {
            b[++m]=border{a[i].L,i,-1};
            b[++m]=border{a[i].R,i,1};
        }
        sort(b+1,b+m+1,cmp2);
        memset(ans,0,(n+1)*sizeof(int));
        process();
        for(int i=1;i<=n;i++)
        {
            if(Lb.count(a[i].L))
                Lb[a[i].L]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(Lb[a[i].L]==1)
                ans[i]--;
        }
        printf("%d\n",*max_element(ans+1,ans+n+1)+cur);
    }
    return 0;
}