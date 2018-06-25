#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
const int N = 1e5+5;

int n, m;
vector<int> E[N];
int A[N], B[N], pos[N], vis[N], fa[N];
long long sum[N], add[N];
inline bool cmp(int x, int y) { return A[x] < A[y]; }
inline int find(int x) { return (x == fa[x]) ? x : (fa[x] = find(fa[x])); }
int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) E[i].clear();
        for(int i = 1; i <= n; ++i) {
            pos[i] = i; vis[i] = 0; fa[i] = i;
            scanf("%d %d", &A[i], &B[i]);
            A[i] = max(0, A[i] - B[i]);
            add[i] = A[i];
            sum[i] = B[i];
        }

        sort(pos+1, pos+n+1, cmp);
        for(int i = 0; i < m; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            E[a].push_back(b);
            E[b].push_back(a);
        }

        for(int i = 1; i <= n; ++i) {
            vis[pos[i]] = 1;
            for(int j = 0; j < E[pos[i]].size(); ++j) {
                int tt = E[pos[i]][j];
                if(vis[tt]) {
                    int f1 = find(pos[i]); int f2 = find(tt);
                    if(f1 != f2) {
                        sum[f1] += sum[f2];
                        fa[f2] = f1; 
                        add[f1] = min(add[f1], add[f2] + max(0ll, A[f1] - add[f2] - sum[f2])); 
                    }
                }
            }
        }
        printf("%lld\n", sum[pos[n]] + add[pos[n]]);
    }
    return 0;
}