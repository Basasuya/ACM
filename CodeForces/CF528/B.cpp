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
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        // bool flag = true;
        for(int i = 1; i <= n; ++i) {
            if(n % i == 0) {
                int tt = n / i;
                if(tt < k) {
                    printf("%lld\n", 1ll * i * k + tt);
                    break;
                }
            }
        }
    }
    return 0;
}