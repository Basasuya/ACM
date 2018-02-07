#include<iostream>
#include<map>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e6+5;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)

int a[N];
char ok[N];
int fa[N];

int find(int x) { return fa[x] = fa[x] == x? x: find(fa[x]); }
vector<int> vc[N];
vector<int> order[N];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) fa[i] = i;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		scanf("%s", ok);
		for(int i = 0; i < n-1; ++i) {
			if(ok[i] == '1') {
				int t1 = find(i); int t2 = find(i + 1);
				fa[t1] = t2;
			}
		}
		for(int i = 0; i < n; ++i) {
			int t1 = find(i);
			vc[t1].push_back(a[i]);
			order[t1].push_back(i);
		}


		for(int i = 0; i < n; ++i) {
			if(vc[i].size() > 1) {
				sort(vc[i].begin(), vc[i].end());
				sort(order[i].begin(), order[i].end());

				for(int j = 0; j < vc[i].size(); ++j) {
					//		printf("%d ", vc[i][j]);
					a[order[i][j]] = vc[i][j];
				}
				//	printf("\n");
			}
		}
		int flag = 1;
		for(int i = 0; i < n-1 && flag; ++i) {
			if(a[i] > a[i+1]) {
				flag = 0;
			} 
		}

		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
