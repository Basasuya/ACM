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

int a[N], c[N];
int t[N], d[N];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &c[i]);
        }

        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &t[i], &d[i]);
        }

        ll cost = 0;
        set<pair<int, int> > st;
        for(int i = 1; i <= n; ++i) {
            st.insert(make_pair(c[i], i));
        }
        for(int i = 0; i < m; ++i) {
            int tag = t[i]; ll tmp = 0;
            if(a[tag] >= d[i]) {
                a[tag] -= d[i];
                tmp += 1ll * d[i] * c[tag];
                if(a[tag] == 0) {
                    st.erase(make_pair(c[tag], tag));
                }
            } else {
                int times = d[i];
                if(a[tag]) {
                    tmp += 1ll * a[tag] * c[tag];
                    times -= a[tag];
                    a[tag] = 0;
                    st.erase(make_pair(c[tag], tag));
                }
                bool suc = true;
                // printf("%d %d\n", tag, times);
                while(times) {
                    if(st.empty()) {
                        suc = false;
                        break;
                    }
                    auto top = *st.begin();
                    int t1 = top.first; int t2 = top.second;
                    // printf("%d %d\n", t1, t2);
                    if(a[t2] > times) {
                        tmp += 1ll * times * c[t2];
                        a[t2] -= times;
                        times = 0;
                    } else {
                        tmp += 1ll * a[t2] * c[t2];
                        times -= a[t2];
                        a[t2] = 0;
                        st.erase(top);
                    }
                }
                if(!suc) tmp = 0;
                
            }
            printf("%lld\n", tmp);
            // cost += tmp;
        }
        // printf("%lld\n", cost);
    }
    return 0; 
}