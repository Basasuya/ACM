#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 105;
const int INF = 0x3f3f3f3f;

int X[N], Y[N];

int Count(int x1, int x2, int y1, int y2) {
    if(y1 < x1) {
        if(y2 < x1) return 0;
        else if(y2 <= x2) 
            return y2 - x1 + 1;
        else return x2 - x1 + 1;
    } else if(y1 <= x2) {
        if(y2 <= x2) 
            return y2 - y1 + 1;
        else return x2 - y1 + 1;
    } else 
        return 0;
}
int main() {
    int n, m, x, y;
    while(~scanf("%d %d %d %d", &n, &m, &x, &y)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &X[i]);
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &Y[i]);
        }

        sort(X+1, X + n + 1);
        sort(Y+1, Y + m + 1);
        
        bool flag = false;
        for(int i = x + 1; i < y && !flag; ++i) {
            if(i > X[n] && i <= Y[1]) {
                flag = true;
            }
        }
        printf("%s\n", flag ? "No War" : "War");
    }
    return 0;
}
