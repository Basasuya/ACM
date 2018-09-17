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
const int N = 105;
const int INF = 0x3f3f3f3f;

int a[N];
int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        multiset<int> st;

        int maxx = -1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            maxx = max(maxx, a[i]);
            st.insert(a[i]);
        }

        int tmp = m;
        while (tmp--) {
            int tt = *st.begin();
            st.erase(st.begin());
            st.insert(tt + 1);
        }

        printf("%d %d\n", *(--st.end()), maxx + m);
    }
    return 0;
}