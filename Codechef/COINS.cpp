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
typedef long long ll;
const int N = 1005;
const int INF = 0x3f3f3f3f;

map<int, ll> mp;
ll solve(int x) {
    if (mp.find(x) != mp.end()) return mp[x];
    ll tt = solve(x / 4) + solve(x / 2) + solve(x / 3);
    if (tt < x) tt = x;
    mp[x] = tt;
    return tt;
}
int main() {
    // for (int i = 1; i <= 1000; ++i) {
    //     if (i <= i / 2 + i / 3 + i / 4) {
    //         printf("%d\n", i);
    //     }
    // }
    // printf("\n");
    int n;
    mp.clear();
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 4;
    while (~scanf("%d", &n)) {
        printf("%lld\n", solve(n));
    }
    return 0;
}