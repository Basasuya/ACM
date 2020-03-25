#include<iostream>
#include<cstdio>
#define maxn 1000
using namespace std;
int n,m,f[maxn][maxn],head[maxn],cnt;
struct edge
{
    int to,pre; 
}e[maxn];
inline int in()
{
    char a=getchar();
    while(a<'0'||a>'9')
    {
        a=getchar();
    }
    int t=0;
    while(a>='0'&&a<='9')
    {
        t=(t<<1)+(t<<3)+a-'0';
        a=getchar();
    }
    return t;
}
void add(int from,int to)
{
    e[++cnt].pre=head[from];
    e[cnt].to=to;
    head[from]=cnt;
}
void dp(int now)
{
//    f[now][0]=0;
    for(int i=head[now];i;i=e[i].pre)
    {
        int go=e[i].to;
        dp(go);
        for(int j=m+1;j>=1;j--)
        {
            for(int k=0;k<j;k++)
            {
                f[now][j]=max(f[now][j],f[go][k]+f[now][j-k]);
            }
        }
    }
}
int main()
{
    n=in(),m=in();
    for(int i=1;i<=n;i++)
    {
        int fa=in();
        f[i][1]=in();
        add(fa,i);
    }
    dp(0);
    printf("%d\n",f[0][m+1]);
    return 0;
}