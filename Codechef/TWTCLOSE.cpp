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
const int N = 1005;
const int INF = 0x3f3f3f3f;

int ans[1005][1005];
int main() {
    int n, k;
    while (~scanf("%d %d", &n, &k)) {
        int tot = 0;
        int now = 0;
        for (int i = 0; i < k; ++i) {
            char seq[15];
            int d;
            scanf("%s", seq);
            if (seq[2] == 'I') {
                scanf("%d", &d);
                ans[tot][d] ^= 1;
                now += ans[tot][d] ? 1 : -1;
            } else {
                now = 0;
                tot++;
            }
            printf("%d\n", now);
        }
    }
    return 0;
}