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
const int MOD = 998244353;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int d; scanf("%d", &d);
        double t1 = d*d - 4*d;
        if(t1 < 0) {
            printf("N\n");
            continue;
        }
        t1 = sqrt(t1);
        printf("Y %.9f %.9f\n", (t1 + d) / 2, (d - t1) / 2);
    }
    return 0;
}