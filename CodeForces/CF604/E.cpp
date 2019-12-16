#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int maxn=2e5+5;
const int mod=998244353;
int n,p[maxn];
inline int ksm(int x,int k){
	int s=1;
	for(;k;k>>=1,x=1ll*x*x%mod)if(k&1)s=1ll*s*x%mod;
	return s;
}
int dp[maxn];
int main(){
	n=read();
	int inv=ksm(100,mod-2);
	for(int i=1;i<=n;i++){
		p[i]=read();
		p[i]=1ll*p[i]*inv%mod;
	}
	dp[1]=0;
	for(int i=2;i<=n+1;i++)dp[i]=1ll*(dp[i-1]+1)*ksm(p[i-1],mod-2)%mod;
	cout<<dp[n+1]<<'\n';
	return 0;
}
 