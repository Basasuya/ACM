#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
const int MAXN = 1e6+5;
int n,num[MAXN];
double a[MAXN],p[MAXN];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        int pos=0;
        rep(i,1,n){
            scanf("%lf",&a[i]);
            p[++pos]=a[i],num[pos]=1;
            while(pos>1&&p[pos-1]>p[pos]){
                p[pos-1]=(p[pos-1]*num[pos-1]+p[pos]*num[pos])/(num[pos-1]+num[pos]);
                num[pos-1]+=num[pos];
                pos--;
            }
        }
        rep(i,1,pos){
            rep(j,1,num[i])printf("%.10lf\n",p[i]);
        }
    }
    return 0;
}
