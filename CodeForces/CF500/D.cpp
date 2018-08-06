#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long ll; 
const int N = 200005;
const int INF = 0x3f3f3f3f;

int f[N]; //col
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }

vector<int> row[N];
vector<int> col[N];

vector<int> part[N];
int has[N];

int tag[N];
int main() {
    int n, m, q;
    while(~scanf("%d %d %d", &n, &m, &q)) {
        for(int i = 1; i <= m; ++i) f[i] = i;
        for(int i = 0; i < q; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            row[a].push_back(b);
            tag[a] ++;
            col[b].push_back(a);
            has[b] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < row[i].size(); ++j) {
                int t1 = row[i][0];
                int t2 = row[i][j];
                int f1 = find(t1); int f2 = find(t2);
                if(f1 != f2) {
                    f[f2] = f1;
                }
            }
        }

        for(int i = 1; i <= m; ++i) {
            int tt = find(i);
            part[tt].push_back(i);
        }

        int cnt = 0; int cntPart = 0;
        for(int i = 1; i <= m; ++i) {
            if(!has[i]) continue;
            if(part[i].size() > 0) {
                cntPart ++;
                cnt += part[i].size();
            }
        }

        int result = 0;
        for(int i = 1;  i <= n; ++i) {
            if(!tag[i])
                result ++;
        }
    //    printf("%d\n", cnt);
        printf("%d\n", result + cntPart - 1 - cnt + m);
    }
    return 0;
}