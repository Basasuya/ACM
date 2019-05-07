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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;
int n, k;
struct Node{
    int l, r;
    bool operator < (const Node &T) const {
        if(l != T.l) return l < T.l;
        else return r < T.r;
    }
}E[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {

        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &E[i].l, &E[i].r);
        }
        sort(E, E + n);
        multiset<pair<int, int> > PR;
        multiset<int> st;
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            // printf("do %d %d\n", E[i].l, E[i].r);
            PR.insert(make_pair(E[i].r, E[i].l));
            st.insert(E[i].l);
            while(1) {
                int t1 = *(--st.end());
                pair<int, int> tt = (*(PR.begin()));
                int t2 = tt.first; 
                int t3 = tt.second;
                if(t1 >= t2 || st.size() > k) {
                    // printf("find: %d %d %d\n", t1, t2, t3);
                    PR.erase(PR.begin());
                    st.erase(st.find(t3));
                } else break;
            }
            if(st.size() >= k) {
                int t1 = *(--st.end());
                int t2 = (*(PR.begin())).first;
                // printf("%d %d\n", t1, t2);
                ans = max(ans, t2 - t1);
            } 
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
1
3 2
1 6
2 4
3 6

*/