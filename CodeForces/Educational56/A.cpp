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


int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int x; scanf("%d", &x);

        int t1 = x % 2;
        int t2 = x / 2;
        // if(t1) t2 --;
        printf("%d\n", t2);
    }
    return 0;
}