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

int a[N];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int Min = INF; int Max = -1;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            Min = min(Min, a[i]);
            Max = max(Max, a[i]);
        }

        printf("%d\n", Max - Min - n + 1);

    }
    return 0;
}