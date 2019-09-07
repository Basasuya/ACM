#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=110,M=10100;
int n,m,x,used[M],vis[N],p[N],g[N][N],rp[N][N];
VI row[N],cc[N],rr[N];
int dfs(int u) {
	rep(v,0,n) if (g[u][v]&&!vis[v]) {
		vis[v]=1;
		if (p[v]==-1||dfs(p[v])) { p[v]=u; return 1;}
	}
	return 0;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) {
		scanf("%d",&x); --x;
		row[i].pb(x);
	}
	rep(col,0,m) {
		rep(i,0,n) rep(j,0,n) g[i][j]=0,rp[i][j]=-1;
		rep(i,0,n) for (auto x:row[i]) if (!used[x]) {
			g[i][x/m]=1; rp[i][x/m]=x;
		}
		rep(i,0,n) p[i]=-1;
		rep(i,0,n) {
			memset(vis,0,sizeof(vis));
			assert(dfs(i));
		}
		rep(i,0,n) {
			int x=rp[p[i]][i];
			assert(x!=-1);
			used[x]=1;
			rr[p[i]].pb(x);
			cc[col].pb(x);
		}
	}
	rep(i,0,n) rep(j,0,m) printf("%d%c",rr[i][j]+1," \n"[j==m-1]);
	rep(j,0,m) sort(all(cc[j]));
	rep(i,0,n) rep(j,0,m) printf("%d%c",cc[j][i]+1," \n"[j==m-1]);

}
