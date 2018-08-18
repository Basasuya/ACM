#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
const int N = 2e5+5;

int n, q;
int a[N];
int tree[N];
vector<int> vc[N];
set<int> st;

void Add(int pos, int val) {
    for(int i = pos; i <= n; i += i & -i) {
        tree[i] += val;
    }
}
int Sum(int pos) {
    int sum = 0;
    for(int i = pos; i; i -= i & -i) {
        sum += tree[i];
    }
    return sum;
}
int main() {
    while(~scanf("%d %d", &n, &q)) {
        for(int i = 1; i <= n; ++i) vc[i].clear();
        memset(tree, 0, sizeof(tree));
        st.clear();

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if(a[i])
                vc[a[i]].push_back(i);
            else 
                st.insert(i);
        }

        int qFlag = vc[q].size() == 0;
        int flag = 1;
        for(int i = q; i >= 1 && flag; --i) {
            for(int j = 1; j < vc[i].size() && flag; ++j) {
                int t1 = vc[i][j-1]; int t2 = vc[i][j];
                int sum = Sum(t2 - 1) - Sum(t1);
                if(sum != t2 - t1 - 1) {
                    auto loc2 = st.lower_bound(t2);
                    auto loc1 = st.lower_bound(t1);
                //    printf("i:%d t1:%d, t2:%d\n", i, t1, t2);
                    for(auto j = loc1; j != loc2; ++j) {
                //        printf("%d\n", *j);
                        if(qFlag) {
                            Add(*j, 1);
                            a[*j] = q;
                            qFlag = 0;
                            vc[q].push_back(*j);
                        }else {
                            Add(*j, 1);
                            a[*j] = i;
                        }
                    }
                    int sum = Sum(t2 - 1) - Sum(t1);
                    flag &= sum == (t2 - t1 - 1);
                    st.erase(loc1, loc2);
                }
            }

            for(int j = 0; j < vc[i].size() && flag; ++j) {
                Add(vc[i][j], 1);
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) {
                if(vc[q].size() == 0) {
                    vc[q].push_back(i);
                    a[i] = q;
                }
                else a[i] = 1;
            }
        }

        if(vc[q].size() == 0) flag = 0;

        if(flag) {
            printf("YES\n");
            for(int i = 1; i <= n; ++i) {
                printf("%d ", a[i]);
            }
            printf("\n");
        } else printf("NO\n");
    }
    return 0;
}