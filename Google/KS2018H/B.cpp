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
const int M = 5e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char seq[M];
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_) {
        int n;
        scanf("%d %s", &n, seq + 1);
        int ans = 0; int tmp = 0;
        for(int i = 1; i <= (n+1)/2; ++i) {
            tmp += seq[i] - '0';
        }
        ans = max(ans, tmp);
        for(int i = (n+1)/2 + 1, j = 1; i <= n; ++i, ++j) {
            tmp -= seq[j] - '0';
            tmp += seq[i] - '0';
            ans = max(ans, tmp);
        }


        printf("Case #%d: %d\n", _, ans);

    }
    return 0;
}