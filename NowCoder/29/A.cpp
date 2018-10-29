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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int a[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if(a[i] < 0) ans += 1ll*(i+1) * a[i];
            else ans += a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}