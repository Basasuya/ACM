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
const int N = 105;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int X[N], Y[N], H[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &X[i], &Y[i], &H[i]);
        }
        bool flag = true;
        for(int i = 0; i <= 100 && flag; ++i) {
            for(int j = 0; j <= 100 && flag; ++j) {
                int ans = -INF; bool success = true;
                for(int z = 1; z <= n && success; ++z) {
                    int tt = - abs(i - X[z]) - abs(j - Y[z]);

                    if(H[z] != 0) {
                        if(ans == -INF) ans = -tt + H[z];
                        else if(ans != -tt + H[z]) success = false;
                    }
                }

                if(ans == 0) continue;

                for(int z = 1; z <= n && success; ++z) {
                    int tt = - abs(i - X[z]) - abs(j - Y[z]);
                    if(H[z] == 0) {
                        if(ans < 0) {
                            if(tt == 0) success = false;
                            ans = max(ans, tt);
                        }
                        else if(ans + tt > 0) success = false;
                    }
                }
                if(ans < 0) ans = -ans;

                if(success && ans) {
                    printf("%d %d %d\n", i, j, ans);
                    flag = false;
                }
            }
        }
    }
    return 0;
}