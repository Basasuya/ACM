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

int main() {
    int a, b, c;
    while(~scanf("%d %d %d", &a, &b, &c)) {
        int t1 = a*10 + b + c;
        int t2 = a + 10*b + c;
        int t3 = b + a + c*10;
        printf("%d\n", max(t3, max(t1, t2)));
    }
    return 0;
}