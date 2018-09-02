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
const int N = 505;
int mod;
int ans[N];

int main() {
    int T;
    scanf("%d %d", &T, &mod);
    for(int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas, ans[n]);
    }
}