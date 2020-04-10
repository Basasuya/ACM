#include <stdio.h>
int min(long a,long b)
{
    return a > b ? b : a;
} 
int main()
{
    int T;
    scanf("%d",&T);
    while(T --)
    {
        int n,m,a,b;
        scanf("%d %d %d %d", &n,&m,&a,&b);
        b = b > m ? m : b;
        long long tt = 1ll * n * b / a;
        if(tt == 1) printf("0\n");
        else printf("%lld\n",min(1ll * m, tt));
    }
}