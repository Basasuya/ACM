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
// const int N = 7005;
// const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char seq[105][55];
int tot, Root;
int nx[10005][2];
int tag[10005];
int newNode() {
    nx[tot][0] = nx[tot][1] = -1; tag[tot] = 0;
    return tot ++;
}
int N, P; 

void Insert(char* s) {
    int len = strlen(s);
    int root = Root;
    for(int i = 0; i < len; ++i) {
        int id = s[i] == 'R';
        if(nx[root][id] == -1) {
            nx[root][id] = newNode();
        }
        root = nx[root][id];
    }
    tag[root] ++;
}

ll dfs(int rt, int deep) {
    if(tag[rt]) return 1ll<<(N - deep);
    ll ans = 0;
    if(nx[rt][0] != -1) ans += dfs(nx[rt][0], deep + 1);
    if(nx[rt][1] != -1) ans += dfs(nx[rt][1], deep + 1);
    return ans;
}
int main() {
    freopen("A-large-practice2.in", "r", stdin);
    freopen("A-large-practice2.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_) {
        tot = 0;
        Root = newNode();
        scanf("%d %d", &N, &P);
        for(int i = 0; i < P; ++i) {
            scanf("%s", seq[i]);
            Insert(seq[i]);
        }
        printf("Case #%d: %lld\n", _, (1ll<<N) - dfs(Root, 0));

    }
    return 0;
}