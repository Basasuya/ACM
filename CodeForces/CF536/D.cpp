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

struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int has[N];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(has, 0, sizeof(has));

        for(int i = 0; i < m; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            add(a, b); add(b, a);
        }

        set<int> st;
        st.insert(1);

        while(!st.empty()) {
            int tt = *st.begin(); st.erase(tt); has[tt] = 1;
            printf("%d ", tt);
            for(int i = head[tt]; ~i; i = E[i].nx) {
                if(!has[E[i].to])
                    st.insert(E[i].to);
            }
        }
        printf("\n");


    }
    return 0;
}