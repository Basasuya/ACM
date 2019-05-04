#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int N = 2e5 + 5;

struct Node{
    int di, to, nx;
}E[N << 1];
int head[N], tot;
void add(int fr, int to, int di) {
    E[tot].to = to; E[tot].di = di; E[tot].nx = head[fr]; head[fr] = tot ++;
}

ll dp[N][4]; // (0) 0... (1) 1... (2) 0..1... (3) 1..0...
ll ans;
void dfs(int x, int pre) {
    // printf("%d %d\n", x, pre);
    dp[x][0] = dp[x][1] = 0;
    dp[x][2] = dp[x][3] = 0;
    
    int cnt = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        cnt ++;
        
        dfs(to, x);
        
        // dp[to][E[i].di] ++;

        
        if(E[i].di == 0) {
            ans += dp[x][0] * (dp[to][0] + 1) * 2 + dp[x][0] * (dp[to][1] + dp[to][2]) + (dp[x][1] + dp[x][2]) * (dp[to][0] + 1);
            dp[x][0] += dp[to][0] + 1;
            dp[x][2] += dp[to][1] + dp[to][2];
            
        } else {
            ans += dp[x][1] * (dp[to][1] + 1) * 2 + dp[x][1] * (dp[to][0] + dp[to][3]) + (dp[x][0] + dp[x][3]) * (dp[to][1] + 1);
            dp[x][1] += dp[to][1] + 1;
            dp[x][3] += dp[to][0] + dp[to][3];
        }
    }

    ans += dp[x][0] * 2 + dp[x][1] * 2 + dp[x][2] + dp[x][3];
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        ans = 0;
        memset(head, -1, sizeof(head));
        tot = 0;
        for(int i = 1; i < n; ++i) {
            int fr, to, di; scanf("%d %d %d", &fr, &to, &di); 
            add(fr, to, di); 
            add(to, fr, di);
        }

        ans = 0;
        dfs(1, -1);
        // for(int i = 1; i <= n; ++i) printf("%d: %lld %lld %lld %lld\n", i, dp[i][0], dp[i][1], dp[i][2], dp[i][3]);
        printf("%lld\n", ans);
    }
    return 0;
}