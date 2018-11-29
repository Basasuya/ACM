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
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

// int S[N], R[N];
vector<int> delegant[N];
int prefix[N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= m; ++i) delegant[i].clear();
        memset(prefix, 0, sizeof(prefix));

        for(int i = 0; i < n; ++i) {
            int s, r; scanf("%d %d", &s, &r);
            delegant[s].push_back(r);
        }

        int maxEdge = -1;
        for(int i = 1; i <= m; ++i) {
            sort(delegant[i].begin(), delegant[i].end(), cmp);
            // int edge = delegant[i].size();
            int sum = 0;
            int tag = delegant[i].size();
            for(int j = 0; j < delegant[i].size(); ++j) {
                if(sum + delegant[i][j] < 0) {
                    // edge = j - 1;
                    // sum -= delegant[i][]
                    tag = j;
                    break;
                }
                sum += delegant[i][j];
                prefix[j] += delegant[i][j];
                maxEdge = max(maxEdge, tag);
            }
            prefix[tag] -= sum;
            // minEdge = min(minEdge, edge);
        }

        // for(int i = 1; i <= m; ++i) {
        //     int pre = 0;
        //     for(int j = 0; j < delegant[i].size(); ++j) {
        //         pre += delegant[i][j];
        //         prefix[i].push_back(pre);
        //     }
        // }
        int ans = 0;
        for(int i = 0; i <= maxEdge; ++i) {
            if(i) prefix[i] += prefix[i-1];
            ans = max(ans, prefix[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}