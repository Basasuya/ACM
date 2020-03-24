#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=502;
ll a[M],dp[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	dp[n+1]=0;
	for(ll i=n;i>=1;i--)
	{
		stack<ll> st;
		st.push(a[i]);
		dp[i]=1+dp[i+1];
		for(ll j=i+1;j<=n;j++)
		{
			if(st.top()==a[j])
			{
				ll x=a[j];
				while(1)
				{
					if(sz(st)==0)
					{
						st.push(x);
						break;
					}
					else
					{
						if(st.top()==x)
						{
							st.pop();
							x=x+1;
						}
						else
						{
							st.push(x);
							break;
						}
					}
				}
			}
			else
			{
				st.push(a[j]);
			}
			if(sz(st)==1)
				dp[i]=min(dp[i],1+dp[j+1]);
		}
	}
	cout<<dp[1]<<"\n";
	return 0;
}