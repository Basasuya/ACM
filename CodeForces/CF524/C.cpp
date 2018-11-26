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
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;



ll solve(int x1, int y1, int x2, int y2) {
    // printf("%d %d %d %d\n", x1, y1, x2, y2);
    if(x1 > x2 || y1 > y2) return 0;

    long long t1 = 1ll * (x2 - x1 + 1) * (y2 - y1 + 1);
    ll ans = t1 / 2;
    if(t1 % 2 == 1 && (x1 + y1) % 2 == 0) {
        ans ++;
    }
    // printf("%lld\n", ans);
    return ans;
} 
ll solve2(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;

    return 1ll * (x2 - x1 + 1) * (y2 - y1 + 1);
} 
int main() { 
    int n, m;
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;   
    int T; scanf("%d", &T);
    while(T --) {
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        long long ans = solve(1,1,n,m) - solve(x1,y1,x2,y2) - solve(x3,y3,x4,y4) + solve(max(x1,x3), max(y1, y3), min(x2, x4), min(y2, y4));
        // printf("%lld\n", ans);
        ans += solve2(x1,y1,x2,y2) - solve2(max(x1,x3), max(y1, y3), min(x2, x4), min(y2, y4));
        printf("%lld %lld\n", ans, 1ll*n*m - ans);
    }
    return 0;
}

/*
5
3 4
2 2 3 2
3 1 4 3

*/