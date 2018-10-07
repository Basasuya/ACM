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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(n == 1) {
            printf("Hello World\n");
        } else {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    return 0;
}