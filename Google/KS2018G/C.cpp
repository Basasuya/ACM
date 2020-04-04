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
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 32768;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int n, m, e, sx, sy, tx, ty;
int mp[105][105];
int has[105][105];
int dir[][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
ll energy[N];
int exiting[N];
int remain[N];
int tag[105][105];
vector<tuple<int, int, int> > trap;
int trapNum;
ll dp[N];
void solve(ll all, int id) {
    memset(has, 0, sizeof(has));
    queue<tuple<int, int> > Q;
    Q.push(make_tuple(sx, sy));
    has[sx][sy] = 1;
    int flag = 0;
    int remainNum = 0;
    while(!Q.empty()) {
        int x = get<0>(Q.front()); int y = get<1>(Q.front()); Q.pop();
        if(x == tx && y == ty) {
            flag = 1;
        }
        for(int i = 0; i < 4; ++i) {
            int dx = x + dir[i][0];  int dy = y + dir[i][1];
            if(dx < 1 || dx > n || dy < 1 || dy > m  || has[dx][dy] || mp[dx][dy] == -100000) continue;
            if(mp[dx][dy] < 0 ) {
                remainNum |= 1 << tag[dx][dy]; continue;
            }
            all += mp[dx][dy];
            has[dx][dy] = 1;
            Q.push(make_tuple(dx, dy));
        }
    }
    energy[id] = all;
    exiting[id] = flag;
    remain[id] = remainNum;
}

ll dfs(int mask) {
    if(~dp[mask]) return dp[mask];

    ll ans = -1;
    if(exiting[mask] == 1) ans = energy[mask];

    for(int i = 0; i < trapNum; ++i) {
        if( (remain[mask] >> i) & 1) {
            if(-mp[get<0>(trap[i])][get<1>(trap[i])] <= energy[mask])
                ans = max(ans, dfs(mask | (1<<i)));
        }
    }

    dp[mask] = ans;
    return ans;
}
int main() {
    freopen("./C-large-practice2.in", "r", stdin);
    // freopen("./C-large-practice2.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_){
        trap.clear();
        memset(dp, -1, sizeof(dp));
        scanf("%d %d %d %d %d %d %d", &n, &m, &e, &sx, &sy, &tx, &ty);

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(mp[i][j] < 0 && mp[i][j] != -100000) {
                    trap.emplace_back(i, j, mp[i][j]);
                    tag[i][j] = trap.size() - 1;
                }
            }
        }

        trapNum = trap.size();

        for(int i = 0; i < 1 << trapNum; ++i) {
            ll all = e;
            for(int j = 0; j < trapNum; ++j) {
                if( (i >> j) & 1 ) {
                    mp[get<0>(trap[j])][get<1>(trap[j])] = 0;
                    all += get<2>(trap[j]);
                }
            }

            solve(all, i);

            for(int j = 0; j < trapNum; ++j) {
                if( (i >> j) & 1 ) {
                    mp[get<0>(trap[j])][get<1>(trap[j])] = get<2>(trap[j]);
                }
            }
        }

        // for(int i = 0; i < 1<<trapNum; ++i) printf("%lld %d %d\n", energy[i], remain[i], exiting[i]);

        printf("Case #%d: %lld\n", _, dfs(0));
        
        
        
    }
    return 0;
}

/*


2
4 4 100 1 1 4 4
0 0 0 0
0 0 0 0
0 0 0 -100000
0 0 -100000 0
8 8 250 7 1 1 7
-100000 -100000 -100000 -100000 -100000 -100000 0 -100000
-100000 0 -100000 0 -400 0 0 -100000
-100000 100 -300 0 -100000 -300 -100000 -100000
-100000 0 -100000 500 -100000 250 0 -100000
-100000 -200 -100000 -100000 -100000 -100000 -100 -100000
-100000 0 -100000 0 0 50 50 -100000
0 0 -100 0 -100000 50 -100000 -100000
-100000 -100000 -100000 -100000 -100000 -100000 -100000 -100000


*/