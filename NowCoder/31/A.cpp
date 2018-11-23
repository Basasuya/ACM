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

int n, m;
vector< vector<int> > mp;
char read[N];
vector< vector<int> > vis;
int dir[10][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };

void bfs(int x, int y) {
    if(vis[x][y] == 1 || mp[x][y] == 1) return;
    queue<pair<int, int> > Q;
    vis[x][y] = 1;
    Q.push(make_pair(x, y));
    
    while(!Q.empty()) {
        int tx = Q.front().first; int ty = Q.front().second; Q.pop();
        // printf("%d %d\n", tx, ty);
        for(int i = 0; i < 4; ++i) {
            int dx = tx + dir[i][0]; int dy = ty + dir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] && mp[dx][dy] == 0) {
                vis[dx][dy] = 1;
                Q.push(make_pair(dx, dy));
            }
        }
    }
}
int main() {
    while(~scanf("%d %d", &n, &m)) {
        mp.clear(); vis.clear();
        for(int i = 0; i < n; ++i) {
            vector<int> tmp; vector<int> tmp2;
            scanf("%s", read);
            for(int j = 0; j < m; ++j) {
                tmp.push_back(read[j] != '.');
                tmp2.push_back(0);
            }
            mp.push_back(tmp);
            vis.push_back(tmp2);
        }

        for(int i = 0; i < n; ++i) {
            bfs(i, m - 1); bfs(i, 0);
        }

        for(int i = 0; i < m; ++i) {
            bfs(0, i); bfs(n - 1, i);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(vis[i][j] == 0) ans ++;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}