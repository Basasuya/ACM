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


int a[N];
int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        int tmp = 0; int cnt = 0;
        for(int i = 0; i < n; ++i) {
            a[i] += tmp;
            if(a[i] != 0) {
                cnt ++;
                printf("%d\n", a[i]);
                tmp -= a[i];
            }
            if(cnt == k) break;
        }
        for(int i = 0; i < k - cnt; ++i) printf("0\n");
    }
    return 0;
}