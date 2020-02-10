#include<cstdio>
#include<iostream>
using namespace std;
int n;
double a[1000100],sum;
bool flag;
int l,r;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%lf",&a[i]);
	while(1)
	{
		flag=0;
		l=r=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				flag=1;
				l=r=i;
				sum=a[i];
				while(a[l-1]>=a[l]&&l-1>=1) l--,sum+=a[l];
				while(a[r+1]<a[l]&&r+1<=n)
				{
					if(sum/((r-l+1)*1.0)<(sum+a[r+1])/((r-l+2)*1.0)) break;
					r++;
					sum+=a[r];
				}
				i=r;
				sum/=(r-l+1)*1.0;
				for(int j=l;j<=r;j++) a[j]=sum;
			}
		}
		if(!flag) break;
	}
	for(int i=1;i<=n;i++)
		printf("%.9lf\n",a[i]);
	return 0;
}