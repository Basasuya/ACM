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

int solve(int x) {
    if(x % 2 == 1) return x / 2 - x;
    else return x / 2;
}
int main() {
    int q;
    while(~scanf("%d", &q)) {
        for(int i = 0; i < q; ++i) {
            int l, r; scanf("%d %d", &l, &r);
            printf("%d\n", solve(r) - solve(l - 1));
        }
    }
    return 0;
}