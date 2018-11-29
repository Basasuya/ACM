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
const int N = 2e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int Abs(int x) {
    return x > 0 ? x : -x;
}
int main() {

    int t;
    scanf("%d", &t);
    while(t -- ){
        int n, x, y, d;
        scanf("%d %d %d %d", &n, &x, &y, &d);

        if(Abs(y - x) % d == 0 ||  Abs(1 - y) % d == 0 ||  Abs(n - y) % d == 0 ) {
            int t1 = (Abs(y - x) + d - 1) / d;
            if(Abs(y - x) % d != 0) t1 = INF;
            int t2 = (Abs(x - 1) + d - 1) / d + (Abs(y - 1) + d - 1) / d;
            if(Abs(1 - y) % d != 0) t2 = INF;
            int t3 = (Abs(x - n) + d - 1) / d + (Abs(y - n) + d - 1) / d;
            if(Abs(n - y) % d != 0) t3 = INF;
            printf("%d\n", min(min(t1, t2), t3) );
        } else printf("-1\n");
    }
    return 0;
}