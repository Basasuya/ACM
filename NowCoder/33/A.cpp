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
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;


int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        ll l, r, x;
        scanf("%lld %lld %lld", &l, &r, &x);
        printf("%lld\n", r / x - (l - 1) / x);
    }
    return 0;
}