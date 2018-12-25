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

vector<int> E[N];
int deg[N];
int fa[N];
int main() {
    int n, s;
    while(~scanf("%d %d", &n, &s)) {
        for(int i = 1; i < n; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            E[a].push_back(b);
            E[b].push_back(a);
            deg[a] ++;
            deg[b] ++;
        }

        int all = 0;
        for(int i = 1; i <= n; ++i) {
            if(deg[i] == 1) {
                // fa[E[i][0]] ++;
                all ++;
            }
        }

        // int all = 0;
        // for(int i = 1; i <= n; ++i) {
        //     if(fa[i]) all ++;
        // }

        printf("%.9f\n", s *1.0/ all * 2);
    }
    return 0;
}