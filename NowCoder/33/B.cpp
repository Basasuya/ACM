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
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

int X[N];
int has[M];
int ans[M];

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &X[i]);
            has[X[i]] ++;
        }
        for(int i = 1; i <= k; ++i) {
            if(!has[i]) continue;
            for(int j = i; j <= k; j += i) {
                ans[j] += has[i];
            }
        }
        int maxx = -1;
        for(int i = 1; i <= k; ++i) {
            maxx = max(maxx, ans[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= k; ++i) {
            if(ans[i] == maxx) cnt ++;
        }
        printf("%d %d\n", maxx, cnt);
    }
    return 0;
}