#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e5;
 
int A[MAXN+10];
int dp[3][MAXN+10];
 
void solve()
{
	int k[3];
	for (int i = 0; i < 3; ++i)
		scanf("%d", &k[i]);
	int n = k[0] + k[1] + k[2];
	vector<int> a(n);
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < k[j]; ++i)
		{
			int x;
			scanf("%d", &x);
			A[x - 1] = j;
		}
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < MAXN+5; ++i)
			dp[j][i] = 2e6;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int z = int(2e6);
		for (int j = 0; j < 3; ++j)
		{
			z = min(z, dp[j][i-1]);
			dp[j][i] = z + (A[i-1] == j ? 0 : 1);
		}
	}
	printf("%d\n", min(min(dp[0][n],dp[1][n]),dp[2][n]));
}
 
int main()
{
	solve();
	return 0;
}