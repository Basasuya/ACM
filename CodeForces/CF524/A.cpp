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
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        printf("%d\n", (2*n + k - 1) / k + (5*n + k - 1) / k + (8*n + k - 1) / k);
    }
    return 0;
}