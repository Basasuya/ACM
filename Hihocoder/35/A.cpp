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
const int N = 50005;
int ans[N];
int main() {    
    int T, q, n;
    ans[1] = 1;
    scanf("%d %d", &T, &q);
    for(int i = 2; i < N; ++i) {
        ans[i] = 1ll*ans[i-1] * i % q;
    }
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas, ans[n]);
    }
    return 0;
}