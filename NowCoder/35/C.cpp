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
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 233;
typedef long long ll;

int_least32_t bfs(int x, int tar) {
    int has[250];
    memset(has, 0, sizeof(has));

    queue<pair<int, int> > Q;
    int tt = (x * x * x + x * x) % MOD; 
    if(!has[tt]) Q.push(make_pair(tt, 1)), has[tt] = 1;

    int tt2 = (x * x * x - x * x) % MOD;
    if(!has[tt2]) Q.push(make_pair(tt2, 1)), has[tt2] = 1;
    // has[x] = 1;
    while(!Q.empty()) {
        int x = Q.front().first; int y = Q.front().second; Q.pop();
        
        if(x == tar) return y;
        int tt = (x * x * x + x * x) % MOD; 
        if(!has[tt]) Q.push(make_pair(tt, y + 1)), has[tt] = 1;

        int tt2 = (x * x * x - x * x) % MOD;
        if(!has[tt2]) Q.push(make_pair(tt2, y + 1)), has[tt2] = 1;
    }
    return -1;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int a, b;
        scanf("%d %d", &a, &b);

        

        if(a == b) {
            printf("0\n");
            continue;
        }
        if(b >= 233) {
            printf("-1\n");
            continue;
        }

        a %= 233; b %= 233;

        printf("%d\n", bfs(a, b));
    }
    return 0;
}