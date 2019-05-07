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

int score[N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    int T;
    scanf("%d", &T);
    int n, k;
    while(T --) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) scanf("%d", &score[i]);

        int ans = k;
        sort(score, score + n, cmp);
        for(int i = k; i < n; ++i) {
            if(score[i] == score[k-1]) ans ++;
        }
        
        printf("%d\n", ans);
    }
    return 0;
}