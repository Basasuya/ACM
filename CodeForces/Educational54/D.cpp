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
const int N = 3e5 + 5;
const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;


struct Node{
    int fr, to, nx, dis;
}E[N];
int head[N]; int tot = 0; 
void add(int fr, int to, int di) {
    E[tot].to = to; E[tot].dis = di; E[tot].nx = head[fr]; head[fr] = tot ++;
}


int main() {
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        tot = 0;
        memset(head, 0, sizeof(head));

        for(int i = 0; i < m; ++i) {
            int a,b,c;
            scanf("%d %d %d", &a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }

    }
    return 0;
}