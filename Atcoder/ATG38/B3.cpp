#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	vi p(n);
	rep(i,n)cin>>p[i];
	
	vi t(n-k+1);
	{
		int cnt=0,j=1;
		rep(i,n-k+1){
			while(j<i+k){
				if(p[j-1]>p[j])
					cnt++;
				j++;
			}
			t[i]=cnt;
			if(p[i]>p[i+1])
				cnt--;
		}
	}

    // rep(i,n-k+1) printf("%lld ", t[i]); printf("\n");
    
	vi sm(n-k+1);
	{
		set<int> s;
		int j=0;
		rep(i,n-k){
			while(j<i+k+1)
				s.insert(p[j++]);
			if(*s.bg==p[i]&&*prev(s.ed)==p[j-1])
				sm[i+1]=1;
			s.erase(p[i]);
		}
	}
	int ans=0,z=0;
	rep(i,n-k+1)if(!sm[i]){
		if(t[i])ans++;
		else z++;
	}
	ans+=bool(z);
	cout<<ans<<endl;
}
