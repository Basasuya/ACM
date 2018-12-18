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
const int MOD = 1e9 + 7;
typedef long long ll;

int L[N], R[N];
vector<int> has[N];
int tag[N];
int cnt[N];

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(has, 0, sizeof(has));
        memset(cnt, 0, sizeof(cnt));
        memset(tag, 0, sizeof(tag));

        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", &L[i], &R[i]);
            has[L[i]].push_back(i); has[R[i] + 1].push_back(-i);
            // tag[L[i]] = i;
        }

        int tmpAns = 0;
        int nowTag;
        set<int> st;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < has[i].size(); ++j) {
                if(has[i][j] > 0) st.insert(has[i][j]);
                else st.erase(-has[i][j]);
            }
            // if(tag[i]) nowTag = tag[i];
            // printf("stsize %d\n", st.size());
            if(st.size() == 1) {
                int tt = *st.begin();
                // printf("%d %d\n", i, tt);
                cnt[tt] ++;
            }

            if(st.size() > 0) tmpAns ++;
        }
        // for(int i = 1; i <= n; ++i) printf("%d ",  has[i]); printf("\n");
        // for(int i = 1; i <= n; ++i) printf("%d ",  tag[i]); printf("\n");
        // for(int i = 1; i <= m; ++i) printf("%d ",  cnt[i]); printf("\n");

        int ans = INF; int ansPos;
        for(int i = m; i >= 1; --i) {
            if(cnt[i] < ans) {
                ans = cnt[i];
                ansPos = i;
            } 
        }

        printf("%d %d\n", ansPos, n - tmpAns + ans);


    }
    return 0;
}