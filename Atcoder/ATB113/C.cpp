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
// const int M = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int Y[N], P[N];
vector<int> year[N];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) year[i].clear();
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &P[i], &Y[i]);
            year[P[i]].push_back(Y[i]);
        }

        for(int i = 1; i <= n; ++i) {
            sort(year[i].begin(), year[i].end());
        }

        for(int i = 0; i < m; ++i) {
            int id = lower_bound(year[P[i]].begin(), year[P[i]].end(), Y[i]) - year[P[i]].begin();
            printf("%06d%06d\n", P[i], id + 1);
        }
        
        
    }
    return 0;
}