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
// const int M = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int h[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int t, a;
        scanf("%d %d", &t, &a);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
        }
        int pos; double ans = INF;
        for(int i = 0; i < n; ++i) {
            double temple = t  - h[i] * 0.006;
            double absTemple = abs(temple - a);
            if(absTemple < ans) {
                ans = absTemple;
                pos = i + 1;
            }
        }
        printf("%d\n", pos);
    }
    return 0;
}