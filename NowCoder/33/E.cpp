#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long ch=29,ch2=419;
unsigned long long hashs[200007],pw[200007],v[200007];
unsigned long long hashs2[200007],pw2[200007];
int n,q,a,b,c;
char s[200007];
unsigned long long gethash(int x,int y)
{
    int nxt=x+y-1;
    return hashs[nxt]-hashs[x-1]*pw[y];
}
unsigned long long gethash2(int x,int y)
{
    int nxt=x+y-1;
    return hashs2[nxt]-hashs2[x-1]*pw2[y];
}
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<n;i++)
    {
        int tmp=s[i+1]-s[i];
        if(tmp<0)tmp+=26;
        v[i]=tmp+3;
    }
    pw[0]=1;
    for(int i=1;i<=n;i++)
    pw[i]=pw[i-1]*ch,hashs[i]=hashs[i-1]*ch+v[i];
    pw2[0]=1;
    for(int i=1;i<=n;i++)
    pw2[i]=pw2[i-1]*ch2,hashs2[i]=hashs2[i-1]*ch2+v[i];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(gethash(a,c-1)!=gethash(b,c-1)||gethash2(a,c-1)!=gethash2(b,c-1))
        printf("-1\n");
        else
        {
            int tmp=s[a]-s[b];
            if(tmp<0)tmp+=26;
            int tmp2=26-tmp;
            printf("%d\n",min(tmp,tmp2));
        }
    }
}