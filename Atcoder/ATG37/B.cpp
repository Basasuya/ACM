#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
#define MOD 998244353
using namespace std;
int32_t main()
{
	fio();
	int n;
	cin>>n;
	string s;
	cin>>s;
	int a[7]={0};
    //  0: no color, 1: R, 2: B, 3: G, 4: RB, 5: GB, 6: RG
	memset(a,0,sizeof(a));
	a[0]=n;
	int ans=1;

	for(int i=0;i<3*n;i++)
	{
		if(s[i]=='R')
		{
			if(a[5]>0)
			{
				ans*=a[5];
				ans%=MOD;
				a[5]--;
			}
			else if(a[2]>0)
			{
				ans*=a[2];
				ans%=MOD;
				a[2]--;
				a[4]++;
			}
			else if(a[3]>0)
			{
				ans*=a[3];
				ans%=MOD;
				a[3]--;
				a[6]++;
			}
			else
			{
				ans*=a[0];
				ans%=MOD;
				a[0]--;
				a[1]++;
				//cout<<ans<<endl;
			}
		}
		else if(s[i]=='B')
		{
			if(a[6]>0)
			{
				ans*=a[6];
				ans%=MOD;
				a[6]--;
			}
			else if(a[1]>0)
			{
				ans*=a[1];
				ans%=MOD;
				a[1]--;
				a[4]++;
			}
			else if(a[3]>0)
			{
				ans*=a[3];
				ans%=MOD;
				a[3]--;
				a[5]++;
			}
			else
			{
				ans*=a[0];
				ans%=MOD;
				a[0]--;
				a[2]++;
			}
		}
		else
		{
			if(a[4]>0)
			{
				ans*=a[4];
				ans%=MOD;
				a[4]--;
			}
			else if(a[1]>0)
			{
				ans*=a[1];
				ans%=MOD;
				a[1]--;
				a[6]++;
			}
			else if(a[2]>0)
			{
				ans*=a[2];
				ans%=MOD;
				a[2]--;
				a[5]++;
			}
			else
			{
				ans*=a[0];
				ans%=MOD;
				a[0]--;
				a[3]++;
			}
		}
		//cout<<ans<<endl;
	}

	cout<<ans;
}
