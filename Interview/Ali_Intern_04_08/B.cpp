#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int mp[105][105];
int dp[105][105];
int dir[4][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };

int main() {
    int  T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }

        memset(dp, 0, sizeof(dp));
        queue< pair<int, int> > Q;
        dp[0][0] = mp[0][0];
        Q.push({0, 0});
        int ans = mp[0][0];

        while(!Q.empty()) {
            auto ele = Q.front(); Q.pop();
            int xx = get<0>(ele);
            int yy = get<1>(ele);

            // printf("%d %d\n", xx, yy);
            
            for(int i = 0; i < 4; ++i) {
                for(int j = 1; j <= k; ++j) {
                    int tx = xx + dir[i][0] * j; int ty = yy + dir[i][1] * j; 
                    if(tx >= 0 && tx < n && ty >= 0 && ty < n && mp[tx][ty] > mp[xx][yy] && dp[tx][ty] < dp[xx][yy] + mp[tx][ty]) {
                        dp[tx][ty] = dp[xx][yy]+ mp[tx][ty];
                        ans = max(ans, dp[tx][ty]);
                        Q.push({tx, ty});
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}


/*


100
3 1
1 2 5
10 11 6
12 12 7
*/