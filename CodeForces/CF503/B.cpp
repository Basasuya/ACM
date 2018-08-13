#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
const int N = 1005;

int To[N];
int vis[N];
int dfs(int x) {
    if(vis[x]) return x;
    vis[x] = 1;
    return dfs(To[x]);
}
int main() {
    int n;
    while(~scanf("%d", &n)) {

        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            To[i] = x;
        }
        
        for(int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof(vis));
            printf("%d ", dfs(i));
        }
        printf("\n");
    }
    return 0;
}