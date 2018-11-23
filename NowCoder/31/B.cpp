#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

// int mp[105][105];
int n; 
int vis[105][105];

int solve(int x) {
    int mex[100]; int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[x][i] == 0) {
            vis[x][i] = 1;
            mex[solve(i)] ++;
            cnt ++;
            vis[x][i] = 0;
        }
    }
    for(int i = 0; i < 100; ++i) {
        if(mex[i] == 0) {
            return i;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        printf("%d\n", solve(0));
    }
    return 0;
}