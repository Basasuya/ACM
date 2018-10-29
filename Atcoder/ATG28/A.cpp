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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, x%y);
}

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        int tt = gcd(n, m);
        for(int i = 0; i < n; ++i) {
            scanf("%d", )
        }
    }
    return 0;
}