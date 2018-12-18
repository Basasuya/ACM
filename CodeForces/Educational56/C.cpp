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

ll a[N];
ll b[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n / 2; ++i) scanf("%lld", &b[i]);
        b[0] = b[1];
        a[0] = 0; a[n + 1] = b[1];
        for(int i = 1; i <= n / 2; ++i) {
            int fi = i; int la = n - i + 1;
            if(b[i] >= b[i-1]) {
                ll tt = b[i] - b[i-1];
                a[fi] = a[fi - 1] + tt;
                a[la] = a[la + 1];
            } else {
                ll tt = b[i - 1] - b[i];
                a[fi] = a[fi - 1];
                a[la] = a[la + 1] - tt;
            }
        }
        for(int i = 1; i <= n; ++i) printf("%lld ", a[i]); printf("\n");
    }
    return 0;
}