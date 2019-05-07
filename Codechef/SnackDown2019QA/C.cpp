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

int n;
// struct Node{
//     int fr, to, nx, dis;
// }E[N << 1];
// int head[N]; int tot = 0; 
// void add(int fr, int to) {
//     E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
// }
bool cmp(int x, int y) {
    return x > y;
}
int score[N];
ll suf[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        // tot = 0;
        // memset(head, -1, sizeof(head));

        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &score[i]);
        }
        // sort(score + 2, score + n + 1, cmp);
        suf[0] = 0;
        for(int i = 1; i <= n; ++i) {
            suf[i] = suf[i-1] + score[i];
        }
        
        // for(int i = 1; i <= n; ++i) printf("%lld ", suf[i]); printf("\n");

        int ans = 0;
        for(ll i = 1; i <= n; ++i) {
            // printf("%lld\n", i);
            i = i + suf[i] - 1;
            ans ++;
            if(i >= n-1) break;
        }

        printf("%d\n", ans);
    }
    return 0;
}