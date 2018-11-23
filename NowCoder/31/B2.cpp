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
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;
int n;
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        // memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        // printf("%d\n", solve(0));
        if(n == 1) printf("Kozilek, Butcher of Truth\n");
        else printf("Ulamog, the Infinite Gyre\n");
    }
    return 0;
}