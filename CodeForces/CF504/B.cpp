#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    while(~scanf("%lld %lld", &n, &k)) {
        ll tt = (k+1)/2;
        if(k % 2 == 0) tt ++;
        printf("%lld\n", max(min(n, k-1) - tt + 1, 0ll));
    }
    return 0;
}