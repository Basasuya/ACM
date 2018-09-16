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
const int N = 1005;
const int INF = 0x3f3f3f3f;
typedef long long ll;


ll gcd(ll x, ll y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    ll a, b, x, y;
    while(~scanf("%lld %lld %lld %lld", &a, &b, &x, &y)) {
        ll tt = gcd(x, y);
        x /= tt;
        y /= tt;

        printf("%lld\n", min(a /x, b / y));
    }
    return 0;
}