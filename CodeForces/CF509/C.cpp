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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int a[N];
int ans[N];
int main() {
    int n, m, d;
    while(~scanf("%d %d %d", &n, &m, &d)) {
        set<pair<int, int>> st;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i) {
            st.insert(make_pair(a[i], i));
        }

        int days = 0;
        while(!st.empty()) {
            days ++;
            auto iter = *st.begin();
            int t1 = iter.first; int t2 = iter.second;
            ans[t2] = days;
            st.erase(iter);
            while(!st.empty()) {
                auto iter2 = st.lower_bound(make_pair(t1 + d + 1, 0));
                if(iter2 == st.end()) break;
                t1 = (*iter2).first; t2 = (*iter2).second;
           //     printf("%d:%d ", t1, t2);
                ans[t2] = days;
                st.erase(iter2);
            }
        //    printf("\n");
        }
        printf("%d\n", days);
        for(int i = 0; i < n; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}