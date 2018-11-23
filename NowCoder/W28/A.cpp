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
// const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int a, b, l;
    while(~scanf("%d %d %d", &a, &b, &l)) {
        ll x = a; ll y = b;
        int suc = 0;
        while(1) {
            if(x > l) {
                break;
            }
            ll tt = y / x;
            ll t2 = y % x;
            if(t2) tt ++;
            y += x * tt;
            swap(x, y);
            suc ^= 1;
        }
        printf("%s", !suc ? "Yes" : "No");
        x = b; y = a;
        suc = 0;
        while(1) {
            if(x > l) {
                break;
            }
            ll tt = y / x;
            ll t2 = y % x;
            if(t2) tt ++;
            y += x * tt;
            swap(x, y);
            suc ^= 1;
        }
        printf(" %s\n", suc ? "Yes" : "No");
    }
    return 0;
}
